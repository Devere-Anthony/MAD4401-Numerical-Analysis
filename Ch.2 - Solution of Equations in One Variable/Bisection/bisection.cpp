/* bisection.cpp - my implementation of the Bisection method
 * currently being studied for Numerical Analysis
 *
 * NOTE: This only works for the given function defined in 
 * f(), in order to evaluate a different function, f's return 
 * value needs to be changed.
 * 
 * Author: Devere Anthony Weaver
 */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

double f(double x)    // Change return value to evaluate a different function
{
	return (pow(x, 3) + 4*pow(x, 2) - 10);
}

int main()
{
	double a{}, b{}, tol{}, p{};
	int n{}, counter{};
	double fa = f(a);
	
	while (true)
	{
		std::system("clear");
		std::cout << "The Bisection Method\n___________________" << std::endl;
		std::cout << "\nEnter a > ";
		std::cin >> a;
		std::cout << "Enter b > ";
		std::cin >> b;
		std::cout << "Enter number of iterations (n) > ";
		std::cin >> n;
		std::cout << "Enter error tolerance > ";
		std::cin >> tol;

		std::cout << std::setw(20) << "\nIteration" << std::setw(25) << "a"
		<< std::setw(20) << "b" << std::setw(20) << "p" << std::setw(20) << "f(p)"
		<< std::setw(20) << "Error"
		<< "\n___________________________________________________________________________________________________________________"
		<< std::endl;

		for (int i{0}; i < n; i++)
		{
			counter = i+1;
			p = (a+b)/2.;
			double fp = f(p);    // evaluate f at p

			std::cout << std::setw(2) << i + 1 << " | " << std::setw(30) << std::setprecision(10) <<  a 
				  << std::setw(20) << b 
				  << std::setw(20) << p 			  
				  << std::setw(20) << std::setprecision(5) << fp
				  << std::setw(20) << std::setprecision(10) << (b - p)
				  << "\n___________________________________________________________________________________________________________________"
				  << std::endl;

			if (fp == 0 || ((b-a)/2. < tol))    // exact solution found or tolerance reached
				break;   
			if (fa * fp > 0)    // same signs, shift right
			{
				a = p;
				fa = fp;
			}
			else
				b = p;    // different signs, shift left
		}

		std::cout << "\nAfter " << counter << " iterations, the approximation for the root is " 
			  << std::setprecision(10) << p << std::endl;

		std::string cont{};
		std::cout << "\nContinue [y/N] > ";
		std::cin >> cont;
		if (cont == "y" || cont == "Y")
			continue;
		else 
			break;
	} // end while
}

