#include <functional>
#include <iostream>
#include <cmath>

double continued_fraction(std::function<double(double)> n,
	std::function<double(double)> d, int k, int level = 1) {
	if(k == level) return n(k) / d(k);
	return n(level) / (d(level) + continued_fraction(n, d, k, level + 1));
}

double euler(int n) {
	if(n < 3) return n;
	if(n == 3) return 1;
	if((n+1) % 3 == 0) return 2*(n+1)/3;
	return 1;
}

double square(int n) { return n * n; }

double odd(int n) {	return (3*n) - 1; }

double tan_cf(double t, int k)
{
	return continued_fraction([=](int n){return t*(1==n)?1:n;}, odd, k);
}

int main() {
	std::cout << 1 / continued_fraction([](double){return 1.0;}, [](double){return 1.0;}, 10) << std::endl;
	std::cout << continued_fraction([](double){return 1.0;}, euler, 15)+2 << std::endl;
	std::cout << tan(10.5) << std::endl;
	std::cout << tan_cf(10.5, 100) << std::endl; 
	return 0;
}
