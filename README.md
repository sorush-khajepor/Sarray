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
The tests must be run in debug mode, as the Assert function is used to assess the results. For this purpose, a 

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the BSD-3-Clause - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc

