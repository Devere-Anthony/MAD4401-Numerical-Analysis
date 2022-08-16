#include <iostream>
#include<math.h>

void taylorApprox(double y)
{
	double x = y - 1.;
	double approx = 1. + (1./2.)*x - (1./8.)*pow(x, 2.) + (1./16.)*pow(x,3.);
	double error = sqrt(y) - approx;
	std::cout << "Approximation: " << approx << ", Error: " << error << std::endl;
};

int main()
{
	taylorApprox(0.5);
	taylorApprox(.75);
	taylorApprox(1.25);
	taylorApprox(1.5);
}

