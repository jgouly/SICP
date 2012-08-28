#include <functional>
#include <cmath>
#include <iostream>
#include <iomanip>

typedef std::function<double(double)> double_fn;

const double tolerance = 0.00001;

bool close_enough(double a, double b)
{
	return fabs(a - b) < tolerance;
}

double fixed_point(double_fn f, double guess)
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

const double dx = 0.00001;

double_fn derive(double_fn fn)
{
	return [=](double x) {
		return (fn(x + dx) - fn(x)) / dx;
	};
}

double_fn newton_transform(double_fn g)
{
	return [=](double x) {
		return x - (g(x) / (derive(g)(x)));
	};
}

double newtons_method(double_fn g, double guess)
{
	return fixed_point(newton_transform(g), guess);
}

double cube(double n) { return n*n*n; }

double newton_sqrt(double x)
{
	return newtons_method([=](double y) { return (y*y) - x; }, 1.0);
}

int main()
{
	std::cout << std::setprecision(10);
	std::cout << derive(cube)(5) << std::endl;
	std::cout << newton_sqrt(16.0);
	return 0;
}
