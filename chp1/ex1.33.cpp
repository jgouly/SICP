#include <functional>
#include <iostream>

template<typename T>
T filt_accumulate(std::function<T(T, T)> combiner, T null_val, std::function<T(T)> term,
	T a, std::function<T(T)> next, T b, std::function<bool(T)> filter)
{
	if(a > b) return null_val;
	if(filter(a))
	{
		return combiner(term(a), filt_accumulate(combiner, null_val, term, next(a), next, b, filter));
	} else {
		return filt_accumulate(combiner, null_val, term, next(a), next, b, filter);
	}
}

bool all(int n) { return true; }
int id(int n) { return n; }
int inc(int n){ return n + 1; }
int mult(int n, int p){ return n * p; }
int add(int n, int p){ return n + p; }

template<typename T>
T product(std::function<T(T)> term, T a, std::function<T(T)> next, T b)
{
	return filt_accumulate<T>(mult, 1, term, a, next, b, all);
}

template<typename T>
T sum(std::function<T(T)> term, T a, std::function<T(T)> next, T b)
{
	return filt_accumulate<T>(add, 0, term, a, next, b, all);
}

int factorial(int N)
{
	return product<int>(id, 1, inc, N);
}

int main()
{
	std::cout << factorial(3);
	std::cout << std::endl << sum<int>(id, 1, inc, 10);
	std::cout << std::endl << filt_accumulate<int>(add, 0, id, 1, inc, 10, [](int n){return n % 2 == 0;});
	return 0;
}
