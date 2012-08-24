#include <functional>
#include <iostream>
#include <iomanip>
#include <array>
#include <numeric>

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

		std::array<int, N-1> V;
		std::iota(V.begin(), V.end(), 1);
		sum = std::accumulate(V.begin(), V.end(), sum, [&](double s, int k) {
			return s + (f(a + (h * k)) * (k % 2 == 0 ? 2 : 4));
		});
		
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
	std::cout << simpson<100>(cube, 0.0, 1.0) << std::endl;	
	return 0;
}
