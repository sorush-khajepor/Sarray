#ifndef SARRAY_H
#define SARRAY_H

// Handles Debug and Assert functions. Debug functions are not
// employed if SDEBUG is not defined.
#include"sdebug.h"
#include<iostream>
#include<array>


template <class U>
concept Arithmetic = std::is_arithmetic<U>::value;

/*
Sarray is an array of numbers which facilitate arithmetic operations of arrays.
Supported operations are: +, -, *, /, negative, positive, dot product, std::cout, and explicit 
type casting, and promoted implicit type casting.
Type T must be of numeric type such as integer and double because of the purpose of Sarray.
Debug Assert: For arithmetic and assignment operations of arrays must have the same size.
Assumption: Assignment of Sarray with C language array assumes C array has the same size.
Assumption: CopyTo C-language-array assumes the array has the same size as this Sarray.
Note: Implicit type promotion through arithmetic operations is supported. 
*/


template <Arithmetic T, size_t size>
class Sarray {

private:

	std::array<T,size> items;

	
public:

	static const size_t Size = size;
	using Type = T;

	Sarray(){}

	// Construct with scalar
	Sarray(const T rhs)
	{
		for (size_t i = 0;i<size;i++)
		{
			items[i]=rhs;
		}
	}

	Sarray(std::initializer_list<T> rhs)
	{
		for (size_t i = 0; auto item:rhs)
		{
			items[i]=item;
			if (++i==size) break;
			
		}
		
	}

	Sarray(const T rhs[])
	{
		for (size_t i=0;i<size;i++)
			items[i] = rhs[i];
		
	}


	// Casting data type T to type U, like int to double.
	template<Arithmetic U, size_t n>
	operator Sarray<U,n>() {
		Sarray<U,n> array;
		for (size_t i = 0; i < size; i++)
		{
			array[i] = (U)items[i];
		}
		return array;
	}

	
	// Scalar assignment
	virtual Sarray& operator= (const T rhs)
	{
		for (size_t i = 0;i<size;i++)
		{
			items[i]=rhs;
		}
		return *this;
	}

	// C language array assignment
	// This assignment assumes size of rhs is the same as current Sarray.
	virtual Sarray& operator= (const T rhs[])
	{
		for (size_t i = 0;i<size;i++)
		{
			items[i]=rhs[i];
		}
		return *this;
	}


	virtual Sarray<T, size>& operator= (const Sarray<T,size>& rhs)
	{
		items = rhs.items;
		return *this;
	}

	// This Copies Sarray to an C language array
	// This assumes LHS has the same size as this Sarray.
	virtual void copyTo(T lhs[]) const
	{
		for (size_t i = 0; i < items.size(); i++)
		{
			lhs[i] = items[i];
		}
	}

	// Read-Write access to items
	T& operator[](const size_t& i)
	{
		return items[i];
	}

	// Read-only access to items
	const T& operator[] (const size_t& i)const
	{
		return items[i];
	}

	virtual Sarray operator+ () const
	{
		return *this;
	}

	template<Arithmetic U, size_t n>
	auto operator+ (const Sarray<U,n>& rhs) const
	{
		SASSERT(rhs.Size == items.size(), " + operation with different size array.");
		Sarray<decltype(items[0] + rhs[0]), size> result;
		for (size_t i = 0; i < items.size(); i++) {
			result[i] = items[i] + rhs[i];
		}
		return result;
	}

	template<Arithmetic U>
	auto operator+ (const U& rhs) const
	{
		Sarray<decltype(items[0] + rhs), size> result;
		for (size_t i = 0; i < items.size(); i++)
		{
			result[i] = items[i] + rhs;
		}
		return result;
	}

	template<Arithmetic U>
	friend auto operator+ (const U& lhs, const Sarray<T,size>& rhs)
	{
		Sarray<decltype(lhs + rhs.items[0]),size> result;
		result = rhs + lhs;
		return result;
	}

	template<Arithmetic U, size_t n>
	auto operator* (const Sarray<U,n>& rhs) const
	{
		SASSERT(rhs.Size == items.size(), " * operation with different size array.");
		Sarray<decltype(items[0] * rhs[0]), size> result;
		for (size_t i = 0; i < items.size(); i++) {
			result[i] = items[i] * rhs[i];
		}
		return result;
	}

	template<Arithmetic U>
	auto operator* (const U& rhs) const
	{
		Sarray<decltype(items[0] * rhs), size> result;
		for (size_t i = 0; i < items.size(); i++)
		{
			result[i] = items[i] * rhs;
		}
		return result;
	}

	// This handles operation of: scalar + array
	template<Arithmetic U>
	friend auto operator* (const U& lhs, const Sarray<T,size>& rhs)
	{
		Sarray<decltype(lhs * rhs.items[0]),size> result;
		result = rhs * lhs;
		return result;
	}

	auto operator- () const
	{
		return (*this)*T(-1);
	}

	template<Arithmetic U, size_t n>
	auto operator- (const Sarray<U,n>& rhs) const
	{
		SASSERT(rhs.Size == items.size(), " - operation with different size array.");
		Sarray<decltype(items[0] - rhs[0]), size> result;
		for (size_t i = 0; i < items.size(); i++) {
			result[i] = items[i] - rhs[i];
		}
		return result;
	}

	template<Arithmetic U>
	auto operator- (const U& rhs) const
	{
		Sarray<decltype(items[0] - rhs), size> result;
		for (size_t i = 0; i < items.size(); i++)
		{
			result[i] = items[i] - rhs;
		}
		return result;
	}

	// This handles operation of: scalar - array
	template<Arithmetic U>
	friend auto operator- (const U& lhs, const Sarray<T,size>& rhs)
	{
		Sarray<decltype(lhs - rhs.items[0]),size> result;
		result = rhs * T(-1) + lhs;
		return result;
	}

	template<Arithmetic U, size_t n>
	auto operator/ (const Sarray<U,n>& rhs) const
	{
		SASSERT(rhs.Size == items.size(), " / operation with different size array.");
		Sarray<decltype(items[0] / rhs[0]), size> result;
		for (size_t i = 0; i < items.size(); i++) {
			result[i] = items[i] / rhs[i];
		}
		return result;
	}

	template<Arithmetic U>
	auto operator/ (const U& rhs) const
	{
		Sarray<decltype(items[0] / rhs), size> result;
		for (size_t i = 0; i < items.size(); i++)
		{
			result[i] = items[i] / rhs;
		}
		return result;
	}

	// This handles operation of: scalar - array
	template<Arithmetic U>
	friend auto operator/ (const U& lhs, const Sarray<T,size>& rhs)
	{
		Sarray<decltype(lhs / rhs.items[0]), size> result;
		for (size_t i = 0; i < size; i++)
		{
			result[i] = lhs / rhs.items[i];
		}
		return result;
	}

	virtual const T sum() const {
		T s = T(0);
		for (size_t i = 0; i < items.size(); i++)
		{
			s = s + items[i];
		}
		return s;
	}

	virtual const T getVol() const
	{
		T v = T(1);
		for (size_t i = 0; i < items.size(); i++)
		{
			v = v * items[i];
		}
		return v;
	}

	// Inner product or dot product 
	template<Arithmetic U>
	const auto dot(const Sarray<U,size>& rhs)const
	{
		SASSERT(rhs.Size == size, " Dot product with different size array.");
		return (*this * rhs).sum();
	}

	friend std::ostream& operator<<(std::ostream& os, const Sarray& sarray)
	{
		for (size_t i = 0; i < sarray.Size; i++)
		{
			os << std::endl << "Items(" << i << ") = " << sarray[i];
		}
		os << std::endl << std::endl;
		return os;
	}
};

#endif
