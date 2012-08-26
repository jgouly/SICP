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
	while(!close_enough(guess, next))
	{
		guess = next;
		next = f(guess);
	}
	return guess;	
}

int main()
{
	std::cout << std::setprecision(10);
	std::cout << fixed_point([](double n){ return 1+1.0/n;}, 1.0) << std::endl;
	return 0;
}
