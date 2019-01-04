# Sarray

Sarray simplifies working with arrays in C++. It dramatically decreases lines of code used for 
basic arithmetic operations. It is a generic array and 
supports: +, -, *, /, negative, positive, dot product, std::cout, and explicit 
type casting, and promoted implicit type casting.

## Getting Started

Add Sarray header to your project and you are good to go. Below, I show a little bit of what you can do 
with Sarray. For complete features, check test_sarray.cpp file which contains all the features.

```c++
// Add Sarray header
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

	// Cheesecake 🍰, isn't it?
	return 0;
}
```


### Prerequisites

You need only a C++ compiler of version 14 or above to make use of Sarray. If you have CMake installed, you can compile the tests easily (see below).


## Running the tests

A comprehensive set of tests are written for sarray. You can simply compile them by
following the step below and see the results on screen.
In Linux or Mac OS terminal or Windows command prompt run these commands
```
mkdir build
cd build
cmake ..
cmake --build .
```
The executable file will be created in a Debug directory. Therefore, run them by
```
cd Debug
test_sarray.exe
```
in Linux the executable file has no extension.
The tests must be run in debug mode, as the Assert function is used to assess the results. 

## Contributing

Please feel free to contact us if you are interested for adding features. 


## License

This project is licensed under the BSD-3-Clause - see the [LICENSE.md](LICENSE.md) file for details.
