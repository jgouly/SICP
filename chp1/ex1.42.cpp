#include <functional>
#include <iostream>

template <typename T>
struct compose {
	T operator() (T t) { return f1(f2(t)); }

	std::function<T(T)> f1, f2;
};

int inc(int x) { return x + 1; }
int square(int x) { return x * x; }

int main() {
	compose<int> squinc = { square, inc };

	std::cout << squinc(6) << std::endl;

	return 0;
}
