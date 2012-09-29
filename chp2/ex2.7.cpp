#include <array>
#include <algorithm>
#include <limits>

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

	Interval mult(const Interval& I)
	{
		return I;
	}

	Interval operator/(const Interval& I) {
		if(I.spans_zero()) return { std::numeric_limits<double>::quiet_NaN(),
		                            std::numeric_limits<double>::quiet_NaN() };
		return operator*({ 1.0/I.upper, 1.0/I.lower });
	}

	double centre() const {
		return (lower + upper) / 2.0;
	}
	double width() const {
		return (upper - lower) / 2.0;
	}

	bool spans_zero() const {
		return lower < 0 && upper > 0;
	}

	static Interval fromCentreWidth(double centre, double width)
	{
		return { centre - width, centre + width };
	}

	static Interval fromCentrePercent(double centre, double percent)
	{
		double extra = percent * centre / 100.0;
		return { centre - extra, centre + extra };
	}

	double percent() const {
		return width() * 100.0 / centre();
	}
};


int main() {
	Interval I = { 6.12, 7.48 };
	Interval I2 = { 6.11, 7.49 };
	Interval I3 = I+I2;
	//std::cout << I3.lower << std::endl;
	//std::cout << I3.upper << std::endl;
	//std::cout << (I/I2).lower << std::endl;

	Interval IP = Interval::fromCentrePercent(1, 10);
	Interval IP2 = Interval::fromCentrePercent(1, 10);
	auto Ip3 = IP * IP2;
	std::cout << Ip3.centre() << std::endl;
	std::cout << Ip3.percent() << std::endl;
	Interval IC = Interval::fromCentreWidth(5, 10);

	//std::cout << I.width() << " " << I2.width() << " " << I3.width() << std::endl;

	/*
		Ex 2.9
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

	/*
		Ex 2.13
		i1 * i2 = i3
	*/

	return 0;
}
