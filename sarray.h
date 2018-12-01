#ifndef SARRAY_H
#define SARRAY_H
#define SDEBUG
#include"sdebug.h"

#include<iostream>

#ifdef PYBIND
#include "pybind11/include/pybind11/pybind11.h"
namespace py = pybind11;
#endif

/*
Sarray is an array of numbers which facilitate arithmetic operations of arrays.
Type T must be of numeric type such as int and double because of the purpose.
For arithmetic operations arrays must have the same size.
*/
template <class T>
class Sarray {

protected:

	T* _data;
	size_t _size;

public:


	// Data is not allocated in the default constructor.
	Sarray()
	{
		_size = 0;
	}


	Sarray(size_t size_)
	{
		_size = size_;
		_data = new T[_size]();
	}

	Sarray(std::initializer_list<T> rhs) {
		_size = rhs.size();
		_data = new T[_size];
		std::copy(rhs.begin(), rhs.end(), _data);
	}

	Sarray(const T rhs[], size_t size_) {
		_size = size_;
		_data = new T[_size];
		*this = rhs;
	}

	Sarray(const T rhs, size_t size_) {
		_size = size_;
		_data = new T[_size];
		*this = rhs;
	}

	const size_t& getSize() const { return _size; }

	// Casting data type T to type U, like int to double.
	template<class U>
	operator Sarray<U>() {
		Sarray<U> array(_size);
		for (size_t i = 0; i < _size; i++) {
			array[i] = (U)_data[i];
		}
		return array;
	}

	Sarray& operator= (const T& rhs)
	{
		for (size_t i = 0; i < _size; i++) {
			_data[i] = rhs;
		}
		return *this;
	}

	// This assignment assumes size of rhs is the same as current Sarray.
	virtual Sarray& operator= (const T rhs[])
	{
		for (size_t i = 0; i < _size; i++) {
			_data[i] = rhs[i];
		}
		return *this;
	}


	virtual Sarray<T>& operator= (const Sarray<T>& rhs)
	{
		SASSERT(rhs._size == _size, "Assignment with different size array.");
		for (size_t i = 0; i < _size; i++) {
			_data[i] = rhs[i];
		}
		return *this;
	}

	virtual void copyTo(T lhs[]) const
	{
		for (size_t i = 0; i < _size; i++) {
			lhs[i] = _data[i];
		}
	}

	T& operator[](const size_t& i) {
		return _data[i];
	}
	const T& operator[] (const size_t& i)const {
		return _data[i];
	}

	virtual Sarray operator+ () const {
		return *this;
	}

	virtual Sarray operator- () const {
		return (*this)*T(-1);
	}
	virtual Sarray operator+ (const Sarray& rhs) const {
		Sarray arr(_size);
		for (size_t i = 0; i < _size; i++) {
			arr._data[i] = this->_data[i] + rhs._data[i];
		}
		return arr;
	}

	friend Sarray<T> operator+ (const T& lhs, const Sarray<T>& rhs)
	{
		Sarray<T> arr(rhs._size);
		arr = rhs + lhs;
		return arr;
	}

	friend Sarray<T> operator- (const T& lhs, const Sarray<T>& rhs)
	{
		Sarray<T> arr(rhs._size);
		arr = rhs * T(-1) + lhs;
		return arr;
	}

	friend Sarray<T> operator* (const T& lhs, const Sarray<T>& rhs)
	{
		Sarray<T> arr(rhs._size);
		arr = rhs * lhs;
		return arr;
	}

	friend Sarray<T> operator/ (const T& lhs, const Sarray<T>& rhs)
	{
		Sarray<T> arr(rhs._size);
		for (size_t i = 0; i < rhs._size; i++) {
			arr._data[i] = lhs / rhs._data[i];
		}
		return arr;
	}


		virtual Sarray operator+ (const T& rhs) const {
		Sarray arr(_size);
		for (size_t i = 0; i < _size; i++) {
			arr._data[i] = this->_data[i] + rhs;
		}
		return arr;
	}

	virtual Sarray operator- (const Sarray& rhs) const {
		Sarray arr(_size);
		for (size_t i = 0; i < _size; i++) {
			arr._data[i] = this->_data[i] - rhs._data[i];
		}
		return arr;
	}
	virtual Sarray operator- (const T& rhs) const {
		Sarray arr(_size);
		for (size_t i = 0; i < _size; i++) {
			arr._data[i] = this->_data[i] - rhs;
		}
		return arr;
	}
	virtual Sarray operator* (const Sarray& rhs) const {
		Sarray arr(_size);
		for (size_t i = 0; i < _size; i++) {
			arr._data[i] = this->_data[i] * rhs._data[i];
		}
		return arr;
	}


	virtual Sarray operator* (const T& rhs) const {
		Sarray arr(_size);
		for (size_t i = 0; i < _size; i++) {
			arr._data[i] = this->_data[i] * rhs;
		}
		return arr;
	}
	virtual Sarray operator/ (const Sarray& rhs) const {
		Sarray arr(_size);
		for (size_t i = 0; i < _size; i++) {
			arr._data[i] = this->_data[i] / rhs._data[i];
		}
		return arr;
	}

	virtual Sarray operator/ (const T& rhs) const {
		Sarray arr(_size);
		for (size_t i = 0; i < _size; i++) {
			arr._data[i] = this->_data[i] / rhs;
		}
		return arr;
	}

	virtual const T sum() const {
		T s = T();
		for (size_t i = 0; i < _size; i++) {
			s = s + _data[i];
		}
		return s;
	}

	virtual const T getVol() const {
		T v = T(1);
		for (size_t i = 0; i < _size; i++) {
			v = v * _data[i];
		}
		return v;
	}

	// Inner product or dot product 
	virtual const T dot(const Sarray& arr)const
	{
		return (*this * arr).sum();
	}

	// std::cout is defined.
	friend std::ostream& operator<<(std::ostream& os, const Sarray& arr)
	{
		for (size_t i = 0; i < arr.getSize(); i++) {
			os << std::endl << "data(" << i << ") = " << arr[i];
		}
		os << std::endl << std::endl;
		return os;
	}

#ifdef PYBIND
	virtual void print()
	{
		for (size_t i = 0; i < size; i++) {
			py::print("\n data(", i, ") = ", data[i]);
		}
	}
#endif    
};


// Sarray with 2 ranks
// Used for nQxnD tensors
// iX -> first rank
// iY -> second rank
template<class T>
class Sarray2D : public Sarray<T> {
protected:
	// Size of ranks
	size_t dim[2];
	using Sarray<T>::_size;
	using Sarray<T>::_data;
public:

	Sarray2D(size_t sizeX, size_t sizeY)
	{
		_size = sizeX * sizeY;
		dim[0] = sizeX;
		dim[1] = sizeY;
		_data = new T[_size]();
	}


	//X -> plane, Y -> line, Z -> point
	Sarray2D(std::initializer_list<T> rhs, size_t sizeX, size_t sizeY) {
		_size = rhs.size();
		dim[0] = sizeX;
		dim[1] = sizeY;
		_data = new T[size];
		std::copy(rhs.begin(), rhs.end(), _data);
	}

	Sarray2D(const T rhs[], size_t sizeX, size_t sizeY) {
		_size = sizeX * sizeY;
		dim[0] = sizeX;
		dim[1] = sizeY;
		_data = new T[_size]();
		*this = rhs;
	}

	Sarray2D(const T rhs, size_t sizeX, size_t sizeY) {
		_size = sizeX * sizeY;
		dim[0] = sizeX;
		dim[1] = sizeY;
		_data = new T[_size]();
		*this = rhs;
	}
	// Operator () is reserved for accessing elements
	T& operator() (const int& iX, const int& iY) {
		return _data[getSingleIndex(iX, iY)];
	}

	// Constant access to Node through operator ()
	const T& operator() (const int& iX, const int& iY) const {
		return _data[getSingleIndex(iX, iY)];
	}

	// Get single number index of the node from cartesian index
	int getSingleIndex(const int& iX, const int& iY) const { return iX * dim[1] + iY; }

	int getCartIndex(int& i, int& iX, int& iY)
	{
		iX = i / (dim[1]);
		iY = i % (dim[1]);
	}
#ifdef PYBIND
	void print()
	{
		for (size_t i = 0; i < size; i++) {
			size_t iX, iY, iZ;
			getCartIndex(i, iX, iY);

			py::print("\n data(", iX, ",", iY, ") = ", data[i]);
		}
	}
#endif

};


#endif
