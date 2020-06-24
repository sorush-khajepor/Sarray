# Sarray 🌟

Have you found yourself in the endless circle of writing for-loops in numerical projects? 
Sarray simplifies working with arrays in C++ . It dramatically decreases lines of code used for 
basic arithmetic operations. It is a generic array and 
supports: +, -, \*, /, negative, positive, dot product, `std::cout`, assignment, explicit 
type-casting, and promoted implicit type-casting. Sarray is a simple form of `std::valarray` that
can be added to your project and be extended to your need. Sarray is targetting  simplicity than 
efficiency. For interested readers, using [Expression templates](https://en.wikipedia.org/wiki/Expression_templates) is a 
way to improve the efficiency in this kind of programs.

## Getting Started 🏁

Add Sarray header to your project and you are good to go . Below, I show a little bit of what you can do 
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

	
	return 0;
}
```

### Prerequisites 💽

You need only a C++ compiler of version 14 or above to make use of Sarray. If you have CMake installed, you can compile the tests easily (see below).


## Running the tests ✔️

A comprehensive set of tests are written for Sarray in test_sarray.cpp. You can simply compile them by
following the step below and see the results on screen.
In Linux or Mac OS terminal or Windows command prompt run these commands
```bash
mkdir build
cd build
cmake ..
cmake --build .
```
The executable file will be created in a Debug directory. Therefore, run them by
```bash
cd Debug
test_sarray.exe
```
In Linux the executable file has no extension.
The tests are run in the Sdebug mode, as SASSERT function, defined in sdebug.h, is used to assess the results.
Sdebug mode is switched on by definition of 
```c++
#def SDEBUG
```
in the beginning of test_sarray.cpp.

## Contributing 

Please feel free to raise an issue and submit a pull-request.


## License 📃

This project is licensed under the BSD-3-Clause - see the [LICENSE.md](LICENSE.md) file for details.
