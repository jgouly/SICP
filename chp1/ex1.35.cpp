#include <functional>
#include <cmath>
#include <iostream>
#include <iomanip>

const double tolerance = 0.00001;

bool close_enough(double a, double b)
{
	return fabs(a - b) < tolerance;
}

double fixed_point(std::function<double(double)> f, double guess)
{
	double next = f(guess);
	int steps = 1;
	while(!close_enough(guess, next))
	{
		guess = next;
		next = f(guess);
		++steps;
	}
	std::cout << steps << " steps" << std::endl;
	return guess;	
}

int main()
{
	std::cout << std::setprecision(10);
	std::cout << fixed_point([](double n){ return 1+1.0/n;}, 1.0) << std::endl;
	std::cout << fixed_point([](double n) { return log(1000)/log(n);}, 2.0) << std::endl;
	std::cout << fixed_point([](double n) { return (n+log(1000)/log(n))/2.0;}, 2.0) << std::endl;
	return 0;
}
