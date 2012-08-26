#include <functional>
#include <iostream>

template<typename T>
T accumulate(std::function<T(T, T)> combiner, T null_val, std::function<T(T)> term,
	T a, std::function<T(T)> next, T b)
{
	if(a > b) return null_val;
	return combiner(term(a), accumulate(combiner, null_val, term, next(a), next, b));
}

int id(int n) { return n; }
int inc(int n){ return n + 1; }
int mult(int n, int p){ return n * p; }
int add(int n, int p){ return n + p; }

template<typename T>
T product(std::function<T(T)> term, T a, std::function<T(T)> next, T b)
{
	return accumulate<T>(mult, 1, term, a, next, b);
}

template<typename T>
T sum(std::function<T(T)> term, T a, std::function<T(T)> next, T b)
{
	return accumulate<T>(add, 0, term, a, next, b);
}

int factorial(int N)
{
	return product<int>(id, 1, inc, N);
}

int main()
{
	std::cout << factorial(3);
	std::cout << std::endl << sum<int>(id, 1, inc, 10);
	return 0;
}
