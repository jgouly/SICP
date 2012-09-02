#include <array>
#include <algorithm>

#include <iostream>

struct Interval {
	double lower, upper;

	Interval operator+(const Interval& I) {
		return { lower + I.lower, upper + I.upper };
	}

	Interval operator-(const Interval& I) {
		return { lower - I.upper, upper - I.lower };
	}

	Interval operator*(const Interval& I) {
		std::array<double, 4> is = {
			lower * I.lower,
			lower * I.upper,
			upper * I.lower,
			upper * I.upper,
		};
		std::sort(is.begin(), is.end());
		return { is.front(), is.back() }; 
	}

	Interval operator/(const Interval& I) {
		return operator*({ 1.0/I.upper, 1.0/I.lower });
	}

	double width() {
		return (upper - lower) / 2.0;
	}
};

int main() {
	Interval I = { 6.12, 7.48 };
	Interval I2 = { 6.11, 7.49 };
	Interval I3 = I+I2;
	std::cout << I3.lower << std::endl;
	std::cout << I3.upper << std::endl;
	std::cout << (I/I2).lower << std::endl;

	std::cout << I.width() << " " << I2.width() << " " << I3.width() << std::endl;

	/*
		width(I) = (I.upper - I.lower) / 2

		add(I, I2) = { I.lower + I2.lower, I.upper + I2.upper }

		width(add(I, I2)) = ((I.upper + I2.upper) - (I.lower + I2.lower)) / 2

		rearrange width:

			width(I) = (I.upper - I.lower) / 2
			2 * width(I) = I.upper - I.lower
			(2 * width(I)) + I.lower = I.upper

		substitue:
		
		width(add(I, I2)) = (((2 * width(I) + I.lower) + (2 * width(I2) + I2.lower)) - (I.lower + I2.lower)) / 2

		cancel cancel canel

		width(add(I, I2)) = (2 * width(I) + 2 * width(I2)) / 2
		width(add(I, I2)) = width(I) + width(I2)
	*/

	return 0;
}
