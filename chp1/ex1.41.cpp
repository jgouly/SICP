#include <functional>
#include <iostream>

template<class R>
struct double1 {
	double1(std::function<R(R)> func_) : func(func_) {}
	R operator ()(R a) { return func(func(a)); }
	std::function<R(R)> func;
};

int inc(int x) { return x + 1; }

int main()
{
	double1<int> inc1(inc);
	std::cout << inc1(1);	
	return 0;
}

