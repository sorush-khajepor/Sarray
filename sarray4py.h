#include "sarray.h"


// Python Interface 

PYBIND11_MODULE(sarray, m) {
	py::class_<Sarray<int>> sarray(m, "Sarray");
	sarray
		.def(py::init<const int,size_t>())
	  .def("print", &Sarray<int>::print, "Printing content of Sarray");

}

