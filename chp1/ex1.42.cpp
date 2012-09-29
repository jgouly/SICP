#include <functional>
#include <iostream>

/* ex1.42 */
template <typename T>
struct compose {
	T operator() (T t) { return f1(f2(t)); }

	std::function<T(T)> f1, f2;
};

int inc(int x) { return x + 1; }
int square(int x) { return x * x; }

/* ex1.43 */
template<int N, typename T>
struct inner_repeat {
	std::function<T(T)> get(std::function<T(T)> f)
	{
		return compose<T> {inner_repeat<N - 1, T>().get(f), f };
	}
};

template<typename T>
struct inner_repeat<1, T> {
	std::function<T(T)> get(std::function<T(T)> f)
	{
		return f;
	}
};

template<typename T>
struct inner_repeat<0, T> {
	std::function<T(T)> get(std::function<T(T)> f)
	{
		return [](T t) { return t; };
	}
};

template<typename T, int N>
std::function<T(T)> repeat(std::function<T(T)> f)
{
	return inner_repeat<N, T>().get(f);
}

/* ex1.44 */
std::function<double(double)> smooth(std::function<double(double)> fn, double dx)
{
	return [=](double n) {
		return (fn(n-dx) + fn(n) + fn(n + dx)) / 3;
	};
}

template<int N>
std::function<double(double)> smooth_n(std::function<double(double)> fn, double dx)
{
	return repeat<double, N>(smooth(fn, dx));
}

double random_smoothing_fn(double d)
{
	return (2*d) + 0.05;
}

int main() {
	compose<int> squinc { square, inc };
	std::cout << squinc(6) << std::endl;

	auto repeated = repeat<int, 3>(inc);
	std::cout << repeated(5) << std::endl;

	auto random_smoothed = smooth(random_smoothing_fn, 2.5);
	std::cout << random_smoothed(1) << std::endl;
	auto random_smoothed_1 = smooth_n<5>(random_smoothing_fn, 2.5);
	std::cout << random_smoothed_1(1) << std::endl;
	return 0;
}
