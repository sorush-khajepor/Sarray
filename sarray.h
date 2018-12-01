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
Debug Assert: For arithmetic and assignment operations of arrays must have the same size.
Assumption: Assignment of Sarray with C language array assumes C array has the same size.
Assumption: CopyTo C-language-array assumes the array has the same size as this Sarray.
*/
template <class T>
class Sarray {

protected:

	T* _items;
	size_t _size;

private:

	// Set size of Sarray and allocates memory for array items
	void setSize(size_t size) {
		_size = size;
		_items = new T[size]();
	}

public:


	// Data is not allocated in the default constructor.
	Sarray()
	{
		_size = 0;
	}


	Sarray(size_t size)
	{
		setSize(size);
	}

	Sarray(std::initializer_list<T> rhs) {
		setSize(rhs.size());
		std::copy(rhs.begin(), rhs.end(), _items);
	}

	Sarray(const T rhs[], size_t size) {
		setSize(size);
		*this = rhs;
	}

	Sarray(const T rhs, size_t size) {
		setSize(size);
		*this = rhs;
	}

	const size_t& getSize() const { return _size; }

	// Casting data type T to type U, like int to double.
	template<class U>
	operator Sarray<U>() {
		Sarray<U> array(_size);
		for (size_t i = 0; i < _size; i++) {
			array[i] = (U)_items[i];
		}
		return array;
	}

	Sarray& operator= (const T& rhs)
	{
		for (size_t i = 0; i < _size; i++) {
			_items[i] = rhs;
		}
		return *this;
	}

	// C language array assignment
	// This assignment assumes size of rhs is the same as current Sarray.
	virtual Sarray& operator= (const T rhs[])
	{
		for (size_t i = 0; i < _size; i++) {
			_items[i] = rhs[i];
		}
		return *this;
	}


	virtual Sarray<T>& operator= (const Sarray<T>& rhs)
	{
		SASSERT(rhs._size == _size, "Assignment with different size array.");
		for (size_t i = 0; i < _size; i++) {
			_items[i] = rhs[i];
		}
		return *this;
	}

	// This Copies Sarray to an C language array
	// This assumes lhs has the same size as this Sarray.
	virtual void copyTo(T lhs[]) const
	{
		for (size_t i = 0; i < _size; i++) {
			lhs[i] = _items[i];
		}
	}

	// Read-Write access to items
	T& operator[](const size_t& i) {
		return _items[i];
	}

	// Read-only access to items
	const T& operator[] (const size_t& i)const {
		return _items[i];
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
			arr._items[i] = this->_items[i] + rhs._items[i];
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
			arr._items[i] = lhs / rhs._items[i];
		}
		return arr;
	}


	virtual Sarray operator+ (const T& rhs) const {
		Sarray arr(_size);
		for (size_t i = 0; i < _size; i++) {
			arr._items[i] = this->_items[i] + rhs;
		}
		return arr;
	}

	virtual Sarray operator- (const Sarray& rhs) const {
		Sarray arr(_size);
		for (size_t i = 0; i < _size; i++) {
			arr._items[i] = this->_items[i] - rhs._items[i];
		}
		return arr;
	}
	virtual Sarray operator- (const T& rhs) const {
		Sarray arr(_size);
		for (size_t i = 0; i < _size; i++) {
			arr._items[i] = this->_items[i] - rhs;
		}
		return arr;
	}
	virtual Sarray operator* (const Sarray& rhs) const {
		Sarray arr(_size);
		for (size_t i = 0; i < _size; i++) {
			arr._items[i] = this->_items[i] * rhs._items[i];
		}
		return arr;
	}

	virtual Sarray operator* (const T& rhs) const {
		Sarray arr(_size);
		for (size_t i = 0; i < _size; i++) {
			arr._items[i] = this->_items[i] * rhs;
		}
		return arr;
	}

	virtual Sarray operator/ (const Sarray& rhs) const {
		Sarray arr(_size);
		for (size_t i = 0; i < _size; i++) {
			arr._items[i] = this->_items[i] / rhs._items[i];
		}
		return arr;
	}

	virtual Sarray operator/ (const T& rhs) const {
		Sarray arr(_size);
		for (size_t i = 0; i < _size; i++) {
			arr._items[i] = this->_items[i] / rhs;
		}
		return arr;
	}

	virtual const T sum() const {
		T s = T();
		for (size_t i = 0; i < _size; i++) {
			s = s + _items[i];
		}
		return s;
	}

	virtual const T getVol() const {
		T v = T(1);
		for (size_t i = 0; i < _size; i++) {
			v = v * _items[i];
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
	using Sarray<T>::_items;
public:

	Sarray2D(size_t sizeX, size_t sizeY)
	{
		_size = sizeX * sizeY;
		dim[0] = sizeX;
		dim[1] = sizeY;
		_items = new T[_size]();
	}


	//X -> plane, Y -> line, Z -> point
	Sarray2D(std::initializer_list<T> rhs, size_t sizeX, size_t sizeY) {
		_size = rhs.size();
		dim[0] = sizeX;
		dim[1] = sizeY;
		_items = new T[size];
		std::copy(rhs.begin(), rhs.end(), _items);
	}

	Sarray2D(const T rhs[], size_t sizeX, size_t sizeY) {
		_size = sizeX * sizeY;
		dim[0] = sizeX;
		dim[1] = sizeY;
		_items = new T[_size]();
		*this = rhs;
	}

	Sarray2D(const T rhs, size_t sizeX, size_t sizeY) {
		_size = sizeX * sizeY;
		dim[0] = sizeX;
		dim[1] = sizeY;
		_items = new T[_size]();
		*this = rhs;
	}
	// Operator () is reserved for accessing elements
	T& operator() (const int& iX, const int& iY) {
		return _items[getSingleIndex(iX, iY)];
	}

	// Constant access to Node through operator ()
	const T& operator() (const int& iX, const int& iY) const {
		return _items[getSingleIndex(iX, iY)];
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
