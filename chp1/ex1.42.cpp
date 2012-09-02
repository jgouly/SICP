#include <functional>
#include <iostream>

template <typename T>
struct compose {
	T operator() (T t) { return f1(f2(t)); }

	std::function<T(T)> f1, f2;
};

int inc(int x) { return x + 1; }
int square(int x) { return x * x; }

template<int N, typename T>
struct inner_repeat {
	std::function<T(T)> get(std::function<T(T)> f)
	{
		return inner_repeat<N - 1, T>().get(compose<T> { f, f });
	}
};

template<typename T>
struct inner_repeat<1, T> {
	std::function<T(T)> get(std::function<T(T)> f)
	{
		return f;
	}
};

template<typename T, int N>
std::function<T(T)> repeat(std::function<T(T)> f)
{
	return inner_repeat<N, T>().get(f);
}

int main() {
	compose<int> squinc { square, inc };
	std::cout << squinc(6) << std::endl;

	auto repeated = repeat<int, 2>(square);
	std::cout << repeated(5) << std::endl;
	return 0;
}
