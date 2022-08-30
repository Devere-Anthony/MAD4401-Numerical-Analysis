#include <iostream>
#include<math.h>

void taylorApprox(double y)
{
	auto x = y - 1.;
	auto approx = 1. + (1./2.)*x - (1./8.)*pow(x, 2.) + (1./16.)*pow(x,3.);
	auto error = sqrt(y) - approx;
	std::cout << "Approximation: " << approx << ", Error: " << error << std::endl;
};

int main()
{
	taylorApprox(0.5);
	taylorApprox(.75);
	taylorApprox(1.25);
	taylorApprox(1.5);
}

