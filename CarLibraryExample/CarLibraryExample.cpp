#include "CarLibraryExample.h"
#include "Vehicle.h"

#include <stdexcept>

using namespace std;

namespace CarLibrary
{
	double CarLibraryFuncs::Add(double a, double b)
	{
		return a + b;
	}

	double CarLibraryFuncs::Subtract(double a, double b)
	{
		return a - b;
	}

	double CarLibraryFuncs::Multiply(double a, double b)
	{
		return a * b;
	}

	double CarLibraryFuncs::Divide(double a, double b)
	{
		return a / b;
	}
}