#include <functional>
#include <iostream>

double product(std::function<double(double)> term, double a,
	std::function<double(double)> next, double b)
{
	double sum = 1;
	
	while(a < b)
	{
		sum *= term(a);
		a = next(a);
	}
	return sum;
}

double pi_term(double n)
{
	double x = 4 * (n*n);
	return x / (x-1);
}

double inc(double n) { return n+1; }

double id(double n) { return n; }

int main()
{
	std::cout << product(pi_term, 1, inc, 5000)*2 << std::endl;

	std::cout << product(id, 1, inc, 4) << std::endl;
	
	return 0;
}


