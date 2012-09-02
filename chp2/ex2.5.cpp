#include <cmath>
#include <iostream>

struct Pair {
	Pair(int car, int cdr)  {
		value = (int) (std::pow(2, car) * std::pow(3, cdr)); 
	}

	int car() {
		int car, temp = value;
		for(car = 0; temp % 2 == 0; ++car) temp /= 2;
		return car;
	}

	int cdr() {
		int cdr, temp = value;
		for(cdr = 0; temp % 3 == 0; ++cdr) temp /= 3;
		return cdr;
	}

	int value = 0;
};

int main() {
	Pair p(12, 4);
	std::cout << p.car() << std::endl;
	std::cout << p.cdr() << std::endl;
	return 0;
}
