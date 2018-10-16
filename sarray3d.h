#ifndef SARRAY3D_H
#define SARRAY3D_H

#include "sarray.h"

// Sarray with 3 ranks for spatial tensors
// Used for sizeX x sizeY x sizeZ tensors like pressure, temperature, pdf
// This is used for sizeX x sizeZ tensors too.
// For example it can handle 2D and 3D fields: p(x=4,y=3) = 100 bar, p(x=1, y=4, z=5) = 120 bar
// For 2D field, sizeZ = 1, iZ = 0->0

template<class T>
class Sarray3D : public Sarray<T> {
	protected:

		// Size of ranks
		size_t dim[3];
		using Sarray<T>::size;
		using Sarray<T>::data;

	public:
	
	Sarray3D(size_t sizeX, size_t sizeY, size_t sizeZ)
	{
		size = sizeX*sizeY*sizeZ;
		dim[0] = sizeX;
		dim[1] = sizeY;
		dim[2] = sizeZ;
		data = new T[size]();
	}

	//X -> plane, Y -> line, Z -> point
    Sarray3D(std::initializer_list<T> rhs,size_t sizeX, size_t sizeY, size_t sizeZ) 
    {
        size = rhs.size();
	    dim[0]=sizeX;
	    dim[1]=sizeY;
	    dim[2]=sizeZ;
        data = new T[size];
        std::copy(rhs.begin(), rhs.end(), data);
    }

    Sarray3D(const T rhs[], size_t sizeX, size_t sizeY, size_t sizeZ)
    {
        size = sizeX*sizeY*sizeZ;
	    dim[0]=sizeX;
	    dim[1]=sizeY;
	    dim[2]=sizeZ;
        data = new T[size]();
	    *this = rhs;
    }

    Sarray3D(const T rhs,size_t sizeX, size_t sizeY, size_t sizeZ)
    {
        size = sizeX*sizeY*sizeZ;
	    dim[0]=sizeX;
	    dim[1]=sizeY;
	    dim[2]=sizeZ;
        data = new T[size]();
	    *this = rhs;
    }

    // Operator () is reserved for accessing elements
    T& operator() (const int& iX, const int& iY,const int& iZ)
    {
        return data[getSingleIndex(iX,iY,iZ)];
    }

    // Constant access to Node through operator ()
	const T& operator() (const int& iX, const int& iY,const int& iZ) const 
    {
        return data[getSingleIndex(iX,iY,iZ)];
    }

    // Bringing up Sarray assignment
    using Sarray<T>::operator=;

    // Get single number index of the node from cartesian index
    int getSingleIndex (const int& iX, const int& iY, const int& iZ) const
    {
        return iX*(dim[1]*dim[2])+iY*dim[2]+iZ;
    }

    void getCartIndex(size_t& i,size_t& iX,size_t& iY,size_t& iZ)
    {
	    iX = i/(dim[1]*dim[2]);
	    size_t R =i%(dim[1]*dim[2]) ;
	    iY = R/dim[2];
	    iZ = R%dim[2];
    }
#ifdef PYBIND
    void print()
    {
        for (size_t i = 0; i < size; i++)
        {
            size_t iX,iY,iZ;
            getCartIndex(i,iX,iY,iZ);
            py::print( "\n data(", iX,",",iY,",",iZ , ") = ", data[i]);
        }
    }
#endif    
};
#endif
