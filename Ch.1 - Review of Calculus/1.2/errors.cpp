/* errors.cpp - short program to quickly compute the absolute error 
 * and relative error for an exact number and its given approximation */
#include <iostream>
#include <cmath>
#include <numbers>
#include <iomanip>
#include <string>

double absoluteError(double p, double approx)
{
	return (abs(p - approx));
}

double relativeError(double p, double approx)
{
	return (absoluteError(p, approx) / abs(p));
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
		std::cout << "Enter exact > ";
		std::cin >> exact;
		std::cout << "Enter approximate > ";
		std::cin >> approx;

		std::cout << "How many digits to approximate to? > ";
		std::cin >> digits;

		std::cout << "\nExact: " << exact << std::endl;
		std::cout << "Approximate: " << approx << std::endl;
		std::cout << "Absolute Error: " << std::setprecision(digits)
			  << absoluteError(exact, approx) << std::endl;
		std::cout << "Relative Error: " << std::setprecision(digits)
			  << relativeError(exact, approx) << std::endl;

		std::string c{};
		std::cout << "\nContinue [y/N]? > ";
		std::cin >> c;

		if (c == "y" || c == "Y")
			flag = true;
		else 
			flag = false;
		std::cout << std::endl;
	}
}

