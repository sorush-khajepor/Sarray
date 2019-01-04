// Add Sarray 
#include "sarray.h"

int main()
{
	// Let's Define two 3D vectors
	Sarray<double> a = { 1, 2, 4 };
	Sarray<double> b = { 8, 4, 2 };

	// Multiply corresponding elements
	std::cout << a * b;  // gives vector of  (8, 8, 8) 
	
	// Multiply by a number (scalar)
	std::cout << 2 * a; // gives vector of (2, 4, 8)

	// Find dot product
	std::cout << a.dot(b); // gives 24

	// Assignment
	Sarray<double> c;
	c = a;
	std::cout << c; // gives (1,2,4)

	
	// Define an integer vector
	Sarray<int> i = { 1, 1, 1 };

	// Type promotion
	std::cout << i * 1.5;

	// A little bit more complex stuff
	std::cout << b * a / 8.0 * i * 1.234; // gives (1.234, 1.234, 1.234)

	
	std::cout << "Press Enter to close.\n\n";
	std:: cin.get();

	return 0;
}