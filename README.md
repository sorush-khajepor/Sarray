# Sarray

Have you found yourself in the endless circle of writing for-loops in numerical projects? 
Sarray simplifies working with arrays in C++. It dramatically decreases lines of code used for 
basic arithmetic operations. It is a generic array and 
supports: +, -, \*, /, negative, positive, dot product, `std::cout`, assignment, explicit 
type-casting, and promoted implicit type-casting. Sarray is a simple form of `std::valarray` that
can be added to your project and be extended to your need. Sarray is targetting  simplicity than 
efficiency. For interested readers, using [Expression templates](https://en.wikipedia.org/wiki/Expression_templates) is a 
way to improve the efficiency in this kind of programs.

## Getting Started

Add Sarray header to your project and you are good to go . Below, I show a little bit of what you can do 
with Sarray. For complete features, check tests.cpp file which contains all the features.

```c++
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
```

### Prerequisites

You need a C++ compiler of version 20 or above to make use of Sarray. It is tested with g++ v10.2 If you have CMake installed, you can compile the tests easily (see below).


## Running the tests ✔️

A comprehensive set of tests are written for Sarray in test_sarray.cpp. You can simply compile them by
following the step below and see the results on screen.
In Linux or Mac OS or Windows bash terminal run 

```bash
./run_tests
```
The executable file will be created, run them by
```bash
./tests
```
In Windows the executable file has *.exe* extension.
The tests are run in the Sdebug mode, as SASSERT function, defined in *sdebug.h*, is used to assess the results.
Sdebug mode is switched on by definition of 
```c++
#def SDEBUG
```
in the beginning of *tests.cpp*.

## Contributing 

Please feel free to raise an issue and submit a pull-request.


## License

This project is licensed under the BSD-3-Clause - see the [LICENSE.md](LICENSE.md) file for details.
