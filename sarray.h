#ifndef SARRAY_H
#define SARRAY_H

#include<iostream>
#include <assert.h>
#ifdef PYBIND
#include "pybind11/include/pybind11/pybind11.h"
namespace py = pybind11;
#endif

template <class T>
class Sarray{

    protected:

        T* data;
        size_t size;

    public:

    	// Default construction
    	// Data is not allocated here. Becareful for implementaion. 
        Sarray() 
        {
            size = 0;
        }

        Sarray(size_t size_)
        {
            size = size_;
            data = new T[size]();
        }

        Sarray(std::initializer_list<T> rhs) {
            size = rhs.size();
            data = new T[size];
            std::copy(rhs.begin(), rhs.end(), data);
        }

        Sarray(const T rhs[], size_t size_){
            size = size_;
            data = new T[size];
            *this=rhs;
        }

        Sarray(const T rhs, size_t size_){
            size = size_;
            data = new T[size];
            *this=rhs;
        }

        const size_t& getSize() const { return size;}

        template<class U>
        operator Sarray<U>()  {
            Sarray<U> arr(size);
            for (size_t i=0;i<size;i++){
                arr[i] = (U) data[i];
            }
            return arr;
        }

        Sarray& operator= (const T& rhs)
        {

                for (size_t i=0;i<size;i++){
                    data[i] = rhs;
                }
                return *this;
        }

        virtual Sarray& operator= (const T rhs[])
        {
                for (size_t i=0;i<size;i++){
                    data[i] = rhs[i];
                }
                return *this;
        }

        virtual Sarray<T>& operator= (const Sarray<T>& rhs)
        {
                for (size_t i=0;i<size;i++){
                    data[i] = rhs[i];
                }
                return *this;
        }

        virtual void copyTo (T lhs[]) const 
        {
                for (size_t i=0;i<size;i++){
                    lhs[i]=data[i];
                }
        }

        T& operator[](const size_t& i){
            return data[i];
        }
        const T& operator[] (const size_t& i)const{
            return data[i];
        }

        virtual Sarray operator+ () const {
            return *this;
        }

        virtual Sarray operator- () const {
            return (*this)*T(-1);
        }
        virtual Sarray operator+ (const Sarray& rhs) const {
            Sarray arr(size);
            for (size_t i = 0; i < size; i++) {
                arr.data[i] = this->data[i] + rhs.data[i];
            }
            return arr;
        }

        friend Sarray<T> operator+ (const T& lhs,const Sarray<T>& rhs)  
        {
            Sarray<T> arr(rhs.size);
            arr = rhs + lhs;
            return arr;
        }

        friend Sarray<T> operator- (const T& lhs,const Sarray<T>& rhs)  
        {
            Sarray<T> arr(rhs.size);
            arr = rhs*T(-1) + lhs;
            return arr;
        }

        friend Sarray<T> operator* (const T& lhs,const Sarray<T>& rhs)  
        {
            Sarray<T> arr(rhs.size);
            arr = rhs * lhs;
            return arr;
        }

        friend Sarray<T> operator/ (const T& lhs,const Sarray<T>& rhs)  
        {
            Sarray<T> arr(rhs.size);
            for (size_t i = 0; i < rhs.size; i++) {
                arr.data[i] = lhs/rhs.data[i];
            }
            return arr;
        }

        virtual Sarray operator+ (const T& rhs) const {
            Sarray arr(size);
            for (size_t i = 0; i < size; i++) {
                arr.data[i] = this->data[i] + rhs;
            }
            return arr;
        }

        virtual Sarray operator- (const Sarray& rhs) const {
            Sarray arr(size);
            for (size_t i = 0; i < size; i++) {
                arr.data[i] = this->data[i] - rhs.data[i];
            }
            return arr;
        }
        virtual Sarray operator- (const T& rhs) const {
            Sarray arr(size);
            for (size_t i = 0; i < size; i++) {
                arr.data[i] = this->data[i] - rhs;
            }
            return arr;
        }
        virtual Sarray operator* (const Sarray& rhs) const {
            Sarray arr(size);
            for (size_t i = 0; i < size; i++) {
                arr.data[i] = this->data[i] * rhs.data[i];
            }
            return arr;
        }


        virtual Sarray operator* (const T& rhs) const {
            Sarray arr(size);
            for (size_t i = 0; i < size; i++) {
                arr.data[i] = this->data[i] * rhs;
            }
            return arr;
        }
        virtual Sarray operator/ (const Sarray& rhs) const {
            Sarray arr(size);
            for (size_t i = 0; i < size; i++) {
                arr.data[i] = this->data[i] / rhs.data[i];
            }
            return arr;
        }

        virtual Sarray operator/ (const T& rhs) const {
            Sarray arr(size);
            for (size_t i = 0; i < size; i++) {
                arr.data[i] = this->data[i] / rhs;
            }
            return arr;
        }

        virtual const T sum() const {
            T s = T();
            for (size_t i = 0; i < size; i++) {
                s = s + data[i];
            }
            return s;
        }

        virtual const T computeVol() const {
            T v = T(1);
            for (size_t i = 0; i < size; i++) {
                v = v * data[i];
            }
            return v;
        }

        virtual const T dot(const Sarray& arr)const {
            return (*this * arr).sum();
        }
        friend std::ostream& operator<<(std::ostream& os, const Sarray& arr){
            for (size_t i=0;i<arr.getSize();i++){
                os<<std::endl<<"data("<<i<<") = "<<arr[i];
            }
            os<<std::endl<<std::endl;
            return os;
        }
    
#ifdef PYBIND
        virtual void print()
        {
            for (size_t i = 0; i < size; i++) {
                py::print( "\n data(",  i , ") = ", data[i]);
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
		using Sarray<T>::size;
		using Sarray<T>::data;
	public:
	
	Sarray2D(size_t sizeX, size_t sizeY)
	{
		size = sizeX*sizeY;
		dim[0] = sizeX;
		dim[1] = sizeY;
		data = new T[size]();
	}


	//X -> plane, Y -> line, Z -> point
        Sarray2D(std::initializer_list<T> rhs,size_t sizeX, size_t sizeY) {
            size = rhs.size();
	    dim[0]=sizeX;
	    dim[1]=sizeY;
            data = new T[size];
            std::copy(rhs.begin(), rhs.end(), data);
        }

        Sarray2D(const T rhs[], size_t sizeX, size_t sizeY){
            size = sizeX*sizeY;
	    dim[0]=sizeX;
	    dim[1]=sizeY;
            data = new T[size]();
	    *this = rhs;
        }

        Sarray2D(const T rhs,size_t sizeX, size_t sizeY){
            size = sizeX*sizeY;
	    dim[0]=sizeX;
	    dim[1]=sizeY;
            data = new T[size]();
	    *this = rhs;
        }
    // Operator () is reserved for accessing elements
    T& operator() (const int& iX, const int& iY){
        return data[getSingleIndex(iX,iY)];
    }

    // Constant access to Node through operator ()
	const T& operator() (const int& iX, const int& iY) const {
        return data[getSingleIndex(iX,iY)];
    }

    // Get single number index of the node from cartesian index
    int getSingleIndex (const int& iX, const int& iY) const {return iX*dim[1]+iY;}
			
    int getCartIndex(int& i, int& iX, int& iY)
    {
	    iX = i/(dim[1]);
	    iY = i%(dim[1]) ;
    }
#ifdef PYBIND
        void print()
        {
            for (size_t i = 0; i < size; i++) {
		size_t iX,iY,iZ;
		getCartIndex(i,iX,iY);

                py::print( "\n data(", iX,",",iY, ") = ", data[i]);
            }
        }
#endif

};


#endif
