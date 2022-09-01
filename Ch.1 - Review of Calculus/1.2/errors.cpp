/* errors.cpp - short program to quickly compute the absolute error 
 * and relative error for an exact number and its given approximation 
 *
 * Author: Devere Anthony Weaver
 *
 * TODO: Fix spacing and formatting for the output table,
 *       it is useful for now but annoying 
 *
 * TODO: Add more choices for constants
 *
 * TODO: Add some very basic error handling or assertions
 *       to deal with some bad input
 */
#include <iostream>
#include <cmath>
#include <numbers>
#include <iomanip>
#include <string>
#include <ios>

double absoluteError(double p, double approx)
{
	return (fabs(p - approx));
}

double relativeError(double p, double approx)
{
	return (absoluteError(p, approx) / fabs(p));
}

int main()
{
	std::system("clear");
	std::cout << "Compute Absolute Error and Relative Error\n"
		  << "_________________________________________" << std::endl;
	double exact{}, approx{};
	int digits{};
	bool flag{true};

	while (flag)
	{
		std::string constant{};
		std::cout << "Are you using a constant for exact value? [y/N] > ";
		std::cin >> constant;

		if (constant == "y" || constant == "Y")
		{
			// offer choices for constant 
			// TODO: Add more choices as program grows
			int choice{};
			std::cout << "Enter number for corresponding constant" << std::endl;
			std::cout << "1. \u03C0\t\t2. e\n> ";
			std::cin >> choice;
			switch (choice)
			{
				case 1:
					exact = std::numbers::pi;
					break;
				case 2:
					exact = std::numbers::e;
					break;
			}

		}
		else 
		{
			std::cout << "Enter exact > ";
			std::cin >> exact;
		}
		std::cout << "Enter approximate > ";
		std::cin >> approx;
		std::cout << "How many digits to approximate to? > ";
		std::cin >> digits;

		// output
		std::streamsize ss = std::cout.precision();
		std::cout << std::left;
		std::cout << std::setw(20) << "\nExact Value" << std::setw(20) << "Approximate Value"
         	<< std::setw(20)<< "Absolute Error" << std::setw(20) << "Relative Error"  
		<< "\n_________________________________________________________________________" << std::endl;

		std::cout << std::setw(20) << exact << std::setw(20) << approx
		          << std::setw(20) << std::setprecision(digits) << absoluteError(exact, approx)
		          << std::setw(20) << std::setprecision(digits) << relativeError(exact, approx)
		  	  << std::endl;	  

		std::string c{};
		std::cout << "\nContinue [y/N]? > ";
		std::cin >> c;

		if (c == "y" || c == "Y")
		{
			flag = true;
			std::system("clear");
		}
		else 
			flag = false;
		std::cout << std::setprecision(ss) << std::endl;     // reset precision
	}
}

