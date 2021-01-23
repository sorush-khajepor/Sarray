// Add Sarray 
#include "sarray.h"
using namespace std;
int main()
{
	// Let's Define two 3D arrays
	Sarray<double,3> a = { 1, 2, 4 };
	Sarray<int,3>    b = { 4, 2, 1 };

	// Add arrays
	cout<< a + b; // (5, 4, 5) double
	cout<< 1.0+ b; // (5, 3, 2) double

	// Multiply corresponding elements
	cout << a * b;  // (4, 4, 4) double 

	// Multiply by a number (scalar)
	cout << 2 * a; // (2, 4, 8) double

	// Subtract 
    cout<< 2 - b + 1; // (-1, 1, 2) int

	// Division 
	cout<< a/b; // (0.25, 1, 4) double
    cout<< 1/b; //  (0,0,1) int
	cout<< b/2.0; // (2, 1, 0.5) double



	// Find dot product
	std::cout << a.dot(b)<<endl; // 12

	// Assignment
	Sarray<double, 3> c;
	c = a;
	std::cout << c; // (1,2,4)

	// A little bit more complex stuff
    auto r = b * a / 4.0 * b / b * 5;
	std::cout << r; //  (5, 5, 5)

	
	return 0;
}