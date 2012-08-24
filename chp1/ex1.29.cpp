#include <functional>
#include <iostream>
#include <iomanip>

template<bool, int>
struct inner_simpson {
	double operator () (std::function<double(double)> f, double a, double b);
};

template<int N>
struct inner_simpson<true, N> {
double operator () (std::function<double(double)> f, double a, double b)
{
	const double h = (b - a) / N;
	double sum = f(a);

	for(int k = 1; k < N; ++k)
	{
		double x = a + h * k;
		sum += f(x) * (k % 2 == 0 ? 2 : 4);
	}

	sum += f(b);
	return sum * h / 3;
}
};

template<int N>
double simpson(std::function<double(double)> f, double a, double b)
{
	return inner_simpson<N%2==0, N>()(f, a, b);
}

double cube(double s) { return s*s*s; }

int main()
{
	std::cout << std::setprecision(100);
	std::cout << simpson<10>(cube, 0.0, 1.0) << std::endl;	
	return 0;
}
