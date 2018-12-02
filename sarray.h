#ifndef SARRAY_H
#define SARRAY_H
#define SDEBUG
#include"sdebug.h"

#include<iostream>


/*
Sarray is an array of numbers which facilitate arithmetic operations of arrays.
Supported operations are: +, -, *, /, negative, positive, cout, and type casting.
Type T must be of numeric type such as int and double because of the purpose of Sarray.
Debug Assert: For arithmetic and assignment operations of arrays must have the same size.
Assumption: Assignment of Sarray with C language array assumes C array has the same size.
Assumption: CopyTo C-language-array assumes the array has the same size as this Sarray.
Note: Implicit type promotion through arithmetic operations is not supported. The default
behavior is casting the result based on the left hand side of operation. For example,
 Sarray<int> i,
 Sarray<double> d
 i*d returns an array with type Sarray<int>
 d*i returns an array with type Sarray<double>
 To avoid this use explicit casting:
 Sarray<double> i * d returns an array with type Sarray<double>

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

	Sarray(std::initializer_list<T> rhs)
	{
		setSize(rhs.size());
		std::copy(rhs.begin(), rhs.end(), _items);
	}

	Sarray(const T rhs[], size_t size)
	{
		setSize(size);
		*this = rhs;
	}

	Sarray(const T rhs, size_t size)
	{
		setSize(size);
		*this = rhs;
	}

	const size_t& getSize() const { return _size; }

	// Casting data type T to type U, like int to double.
	template<class U>
	operator Sarray<U>() {
		Sarray<U> array(_size);
		for (size_t i = 0; i < _size; i++)
		{
			array[i] = (U)_items[i];
		}
		return array;
	}

	Sarray& operator= (const T& rhs)
	{
		for (size_t i = 0; i < _size; i++)
		{
			_items[i] = rhs;
		}
		return *this;
	}

	// C language array assignment
	// This assignment assumes size of rhs is the same as current Sarray.
	virtual Sarray& operator= (const T rhs[])
	{
		for (size_t i = 0; i < _size; i++)
		{
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
	// This assumes LHS has the same size as this Sarray.
	virtual void copyTo(T lhs[]) const
	{
		for (size_t i = 0; i < _size; i++)
		{
			lhs[i] = _items[i];
		}
	}

	// Read-Write access to items
	T& operator[](const size_t& i)
	{
		return _items[i];
	}

	// Read-only access to items
	const T& operator[] (const size_t& i)const
	{
		return _items[i];
	}

	virtual Sarray operator+ () const
	{
		return *this;
	}

	template<class U>
	auto operator+ (const Sarray<U>& rhs) const
	{
		SASSERT(rhs.getSize() == _size, " + operation with different size array.");
		Sarray<decltype(_items[0] + rhs[0])> result(_size);
		for (size_t i = 0; i < _size; i++) {
			result[i] = _items[i] + rhs[i];
		}
		return result;
	}

	template<class U>
	auto operator+ (const U& rhs) const
	{
		Sarray<decltype(_items[0] + rhs)> result(_size);
		for (size_t i = 0; i < _size; i++)
		{
			result[i] = _items[i] + rhs;
		}
		return result;
	}

	template<class U>
	friend auto operator+ (const U& lhs, const Sarray<T>& rhs)
	{
		Sarray<decltype(lhs + rhs._items[0])> result(rhs._size);
		result = rhs + lhs;
		return result;
	}



	

	


	template<class U>
	auto operator- (const Sarray<U>& rhs) const
	{
		SASSERT(rhs.getSize() == _size, " - operator with different size array.");
		Sarray<decltype(_items[0] - rhs[0])> result(_size);
		for (size_t i = 0; i < _size; i++) {
			result[i] = this->_items[i] - rhs[i];
		}
		return result;
	}

	template<class U>
	auto operator- (const U& rhs) const
	{
		Sarray<decltype(_items[0] - rhs)> result(_size);
		for (size_t i = 0; i < _size; i++) {
			result[i] = this->_items[i] - rhs;
		}
		return result;
	}

	template<class U>
	friend auto operator- (const U& lhs, const Sarray<T>& rhs)
	{
		Sarray<decltype(lhs - rhs[0])> result(rhs._size);
		result = rhs * T(-1) + lhs;
		return result;
	}

	auto operator- () const
	{
		return (*this)*T(-1);
	}

	template<class U>
	auto operator* (const Sarray<U>& rhs) const
	{
		SASSERT(rhs.getSize() == _size, " * operator with different size array.");
		Sarray<decltype(_items[0] * rhs[0])> result(_size);
		for (size_t i = 0; i < _size; i++) 
		{
			result[i] = _items[i] * rhs[i];
		}
		return result;
	}


	template<class U>
	auto operator* (const U& rhs) const
	{
		Sarray<decltype(_items[0] * rhs)> result(_size);
		for (size_t i = 0; i < _size; i++) {
			result[i] = this->_items[i] * rhs;
		}
		return result;
	}

	template<class U>
	friend auto operator* (const U& lhs, const Sarray<T>& rhs)
	{
		Sarray<decltype(lhs * rhs[0])> result(rhs._size);
		result = rhs * lhs;
		return result;
	}

	template<class U>
	auto operator/ (const Sarray<U>& rhs) const
	{
		SASSERT(rhs.getSize() == _size, " / operator with different size array.");
		Sarray<decltype(_items[0] / rhs[0])> result(_size);
		for (size_t i = 0; i < _size; i++) {
			result[i] = _items[i] / rhs[i];
		}
		return result;
	}

	template<class U>
	auto operator/ (const U& rhs) const
	{
		Sarray<decltype(_items[0] / rhs)> result(_size);
		for (size_t i = 0; i < _size; i++)
		{
			result[i] = _items[i] / rhs;
		}
		return result;
	}

	template<class U>
	friend auto operator/ (const U& lhs, const Sarray<T>& rhs)
	{
		Sarray<decltype(lhs / rhs[0])> result(rhs._size);
		for (size_t i = 0; i < rhs._size; i++)
		{
			result[i] = lhs / rhs[i];
		}
		return result;
	}





	virtual const T sum() const {
		T s = T();
		for (size_t i = 0; i < _size; i++)
		{
			s = s + _items[i];
		}
		return s;
	}

	virtual const T getVol() const
	{
		T v = T(1);
		for (size_t i = 0; i < _size; i++)
		{
			v = v * _items[i];
		}
		return v;
	}

	// Inner product or dot product 
	virtual const T dot(const Sarray& rhs)const
	{
		SASSERT(rhs._size == _size, " Dot product with different size array.");
		return (*this * rhs).sum();
	}

	// std::cout is defined.
	friend std::ostream& operator<<(std::ostream& os, const Sarray& sarray)
	{
		for (size_t i = 0; i < sarray.getSize(); i++)
		{
			os << std::endl << "data(" << i << ") = " << sarray[i];
		}
		os << std::endl << std::endl;
		return os;
	}

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
	Sarray2D(std::initializer_list<T> rhs, size_t sizeX, size_t sizeY)
	{
		_size = rhs.size();
		dim[0] = sizeX;
		dim[1] = sizeY;
		_items = new T[size];
		std::copy(rhs.begin(), rhs.end(), _items);
	}

	Sarray2D(const T rhs[], size_t sizeX, size_t sizeY)
	{
		_size = sizeX * sizeY;
		dim[0] = sizeX;
		dim[1] = sizeY;
		_items = new T[_size]();
		*this = rhs;
	}

	Sarray2D(const T rhs, size_t sizeX, size_t sizeY)
	{
		_size = sizeX * sizeY;
		dim[0] = sizeX;
		dim[1] = sizeY;
		_items = new T[_size]();
		*this = rhs;
	}
	// Operator () is reserved for accessing elements
	T& operator() (const int& iX, const int& iY)
	{
		return _items[getSingleIndex(iX, iY)];
	}

	// Constant access to Node through operator ()
	const T& operator() (const int& iX, const int& iY) const
	{
		return _items[getSingleIndex(iX, iY)];
	}

	// Get single number index of the node from cartesian index
	int getSingleIndex(const int& iX, const int& iY) const { return iX * dim[1] + iY; }

	int getCartIndex(int& i, int& iX, int& iY)
	{
		iX = i / (dim[1]);
		iY = i % (dim[1]);
	}

};


#endif
