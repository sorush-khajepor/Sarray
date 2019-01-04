# Sarray

Sarray simplifies working with arrays in C++. It dramatically decreases lines of code used for 
basic arithmetic operations. It is a generic array and 
supports: +, -, *, /, negative, positive, dot product, std::cout, and explicit 
type casting, and promoted implicit type casting.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

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

## Authors

* **Sorush Khajepor**

## License

This project is licensed under the BSD-3-Clause - see the [LICENSE.md](LICENSE.md) file for details.
