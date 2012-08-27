#include <functional>
#include <iostream>

double continued_fraction(std::function<double(double)> n,
	std::function<double(double)> d, int k, int level = 1) {
	if(k == level) return n(k) / d(k);
	return n(k) / (d(k) + continued_fraction(n, d, k, level + 1));
}

int main() {
	std::cout << 1 / continued_fraction([](double){return 1.0;}, [](double){return 1.0;}, 10) << std::endl;
	return 0;
}
