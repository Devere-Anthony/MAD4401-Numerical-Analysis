#include <iostream>
#include<math.h>

double secondTaylorApprox(double x)
{
	return (1.0 + x);
};

int main()
{
	double p2 = secondTaylorApprox(0.5);
	std::cout << "Approximation: " << p2 << std::endl;
}

