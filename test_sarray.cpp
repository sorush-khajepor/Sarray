
/*
Unit tests for Sarray<T> class
*/

// Activates SASSERT which is used for assertion of tests
#define SDEBUG
#include"sarray.h"

// This is added to use abs() function
#include<cmath>

// This is added to implement typeid() function which shows
// the dynamic type of objects.
#include <typeinfo>

typedef Sarray<double> sardouble;
typedef Sarray<int> sarint;

using namespace std;

// Used to assert if two double numbers are equal.
bool IsEqual(double a, double b)
{

	double eps = 0.000001;

	if (abs(a - b) > eps)
	{
		return false;
	}

	return true;

}

int main() {

	// The test should be run in debug mode.
#ifdef NDEBUG
	cout << "Make sure compile in debug mode. Assert function is used"
		"for assessing the tests";
	return 0;
#endif

	// Print Test results on screen.
	bool isPrint = true;

	cout << "===========Testing Constructors==============" << endl;
	{
		cout << "scalar constructor" << endl;
		sardouble c(5.0, 2);
		if (isPrint) cout << " sardouble c(rhs=5.0,size=2) " << endl;
		if (isPrint) cout << c;
		SASSERT(IsEqual(c[0], 5.0) && IsEqual(c[1], 5.0), "Test Failed!");
		SASSERT(c.getSize() == 2, "Test Failed!");
		cout << "   OK. \n\n";
	}

	{
		cout << "Construct with an array ..." << endl;
		double* arr = new double[3]{ 4.0,2.0,1.0 };
		sardouble d(arr, 3);
		if (isPrint) cout << "d = arr[2]={4.0,2.0,1.0}" << endl;
		if (isPrint) cout << d;
		SASSERT(IsEqual(d[0], 4.0) && IsEqual(d[1], 2.0) && IsEqual(d[2], 1.0), "Test Failed!");
		SASSERT(d.getSize() == 3, "Test Failed!");
		cout << "   OK. \n\n";
	}

	{
		cout << "Construct with same-type object ..." << endl;
		sardouble c(5.0, 2);
		sardouble e = c;
		if (isPrint) cout << "sardouble e=c" << endl;
		if (isPrint) cout << e;
		SASSERT(IsEqual(e[0], 5.0) && IsEqual(e[1], 5.0), "Test Failed!");
		SASSERT(e.getSize() == 2, "Test Failed!");
		cout << "   OK. \n\n";
	}
	cout << "Same type constructor 2 " << endl;
	sardouble d(new double[3]{ 4.0,2.0,1.0 } , 3);
	sardouble f(d);
	if (isPrint) cout << "sardouble f(d)" << endl;
	if (isPrint) cout << f;
	SASSERT(IsEqual(f[0], 4.0) && IsEqual(f[1], 2.0) && IsEqual(f[2], 1.0), "Test Failed!");
	SASSERT(d.getSize() == 3, "Test Failed!");
	cout << "   OK. \n\n";

	cout << "List constructor ... " << endl;
	sardouble g{ 1.,2. };
	if (isPrint) cout << "sardouble g = {1.,2.}" << endl;
	if (isPrint) cout << g;
	SASSERT(IsEqual(g[0], 1.0) && IsEqual(g[1], 2.0), "Test Failed!");
	SASSERT(g.getSize() == 2, "Test Failed!");
	cout << "   OK. \n\n";


	cout << "===========Assignment==============" << endl;
	cout << "Scalar assignment " << endl;
	c = 2.1;
	if (isPrint) cout << "c=2.1" << endl;
	if (isPrint) cout << c;
	SASSERT(IsEqual(c[0], 2.1) && IsEqual(c[1], 2.1), "Test Failed!");
	SASSERT(c.getSize() == 2, "Test Failed!");
	cout << "   OK. \n\n";

	cout << "print same type & size assignment ..." << endl;
	sardouble m(3);
	m = d;
	if (isPrint) cout << "sardouble m(3); m=d;" << endl;
	if (isPrint) cout << m;
	SASSERT(IsEqual(m[0], 4.0) && IsEqual(m[1], 2.0) && IsEqual(m[2], 1.0), "Test Failed!");
	SASSERT(m.getSize() == 3, "Test Failed!");
	cout << "   OK. \n\n";



	cout << "===========Unary Operations==============" << endl;
	sardouble un = { 1.5,-2.5 };
	if (isPrint) cout << "un={1.5,-2.5} " << endl;
	cout << "testing operator +un: " << endl;
	un = (+un);
	if (isPrint) cout << un;
	SASSERT(IsEqual(un[0], 1.5) && IsEqual(un[1], -2.5), "Test Failed!");
	SASSERT(un.getSize() == 2, "Test Failed!");
	cout << "   OK. \n\n";

	cout << "Testing operator -un: " << endl;
	un = (-un);
	if (isPrint) cout << un;
	SASSERT(IsEqual(un[0], -1.5) && IsEqual(un[1], 2.5), "Test Failed!");
	SASSERT(un.getSize() == 2, "Test Failed!");
	cout << "   OK. \n\n";

	cout << "===========Operators==============" << endl;
	sardouble h = { 2.0,2.0 };
	if (isPrint) cout << "Array c = {2.1,2.1}, h={2.,2.} is used below." << endl;

	cout << "===========Scalar & array==============" << endl;
	cout << "Right hand side + operator ... " << endl;
	sardouble k(2);
	k = c + 2.1;
	if (isPrint) cout << "k=c+2.1 " << endl;
	if (isPrint) cout << k;
	SASSERT(IsEqual(k[0], 4.2) && IsEqual(k[1], 4.2), "Test Failed!");
	SASSERT(k.getSize() == 2, "Test Failed!");
	cout << "   OK. \n\n";

	cout << "Left hand side + operator ... " << endl;
	k = 2.1 + c;
	if (isPrint) cout << "k=2.1+c " << endl;
	if (isPrint) cout << k;
	SASSERT(IsEqual(k[0], 4.2) && IsEqual(k[1], 4.2), "Test Failed!");
	SASSERT(k.getSize() == 2, "Test Failed!");
	cout << "   OK. \n\n";

	cout << "Right hand side - operator ... " << endl;
	k = c - 2.0;
	if (isPrint) cout << "k=c-2.0 " << endl;
	if (isPrint) cout << k;
	SASSERT(IsEqual(k[0], 0.1) && IsEqual(k[1], 0.1), "Test Failed!");
	SASSERT(k.getSize() == 2, "Test Failed!");
	cout << "   OK. \n\n";

	cout << "Left hand side - operator ... " << endl;
	k = 2.0 - c;
	if (isPrint) cout << "k=2.0-c " << endl;
	if (isPrint) cout << k;
	SASSERT(IsEqual(k[0], -0.1) && IsEqual(k[1], -0.1), "Test Failed!");
	SASSERT(k.getSize() == 2, "Test Failed!");
	cout << "   OK. \n\n";

	cout << "Right hand side * operator " << endl;
	k = c * 2.0;
	if (isPrint) cout << "k=c*2.0 " << endl;
	if (isPrint) cout << k;
	SASSERT(IsEqual(k[0], 4.2) && IsEqual(k[1], 4.2), "Test Failed!");
	SASSERT(k.getSize() == 2, "Test Failed!");
	cout << "   OK. \n\n";

	cout << "Left hand side * operator ..." << endl;
	k = 2.0*c;
	if (isPrint) cout << "k=2.0*c " << endl;
	if (isPrint) cout << k;
	SASSERT(IsEqual(k[0], 4.2) && IsEqual(k[1], 4.2), "Test Failed!");
	SASSERT(k.getSize() == 2, "Test Failed!");
	cout << "   OK. \n\n";

	cout << "Right hand side / operator ..." << endl;
	k = c / 21.0;
	if (isPrint) cout << "k=c/21.0 " << endl;
	if (isPrint) cout << k;
	SASSERT(IsEqual(k[0], 0.1) && IsEqual(k[1], 0.1), "Test Failed!");
	SASSERT(k.getSize() == 2, "Test Failed!");
	cout << "   OK. \n\n";

	cout << "Left hand side / operator ..." << endl;
	k = 0.42 / c;
	if (isPrint) cout << "k=0.42/c " << endl;
	if (isPrint) cout << k;
	SASSERT(IsEqual(k[0], 0.2) && IsEqual(k[1], 0.2), "Test Failed!");
	SASSERT(k.getSize() == 2, "Test Failed!");
	cout << "   OK. \n\n";

	cout << "Mix operator ..." << endl;
	k = k * c / 21.0;
	if (isPrint) cout << "k=c/21.0 " << endl;
	if (isPrint) cout << k;
	SASSERT(IsEqual(k[0], 0.02) && IsEqual(k[1], 0.02), "Test Failed!");
	SASSERT(k.getSize() == 2, "Test Failed!");
	cout << "   OK. \n\n";

	cout << "=========== Sarray-Sarray Operations ==============" << endl;
	if (isPrint) cout << "Array c = {2.1,2.1}, h={2.,2.} is used below." << endl;
	cout << " + operator ... " << endl;
	k = c + h;
	if (isPrint) cout << "k=c+h " << endl;
	if (isPrint) cout << k;
	SASSERT(IsEqual(k[0], 4.1) && IsEqual(k[1], 4.1), "Test Failed!");
	SASSERT(k.getSize() == 2, "Test Failed!");
	cout << "   OK. \n\n";


	cout << " - operator ..." << endl;
	k = c - h;
	if (isPrint) cout << "k=c-h" << endl;
	if (isPrint) cout << k;
	SASSERT(IsEqual(k[0], 0.1) && IsEqual(k[1], 0.1), "Test Failed!");
	SASSERT(k.getSize() == 2, "Test Failed!");
	cout << "   OK. \n\n";


	cout << " * operator ..." << endl;
	k = c * h;
	if (isPrint) cout << "k=c*h" << endl;
	if (isPrint) cout << k;
	SASSERT(IsEqual(k[0], 4.2) && IsEqual(k[1], 4.2), "Test Failed!");
	SASSERT(k.getSize() == 2, "Test Failed!");
	cout << "   OK. \n\n";

	cout << " / operator ..." << endl;
	if (isPrint) cout << "k=c/h" << endl;
	k = c / h;
	if (isPrint) cout << k;
	SASSERT(IsEqual(k[0], 1.05) && IsEqual(k[1], 1.05), "Test Failed!");
	SASSERT(k.getSize() == 2, "Test Failed!");
	cout << "   OK. \n\n";


	cout << "=========== Sarray-Scalar-Sarray (double-int) Mix Operation ==============" << endl;
	if (isPrint) cout << "Sarray<double> c = {2.1,2.1}, h={2.0,2.0}, and Sarray<int> i={1,1} are used below." << endl;
	sarint i = { 1,1 };

	cout << "Mix operator ..." << endl;
	k = i + c / 2.0 * h*i + 1.0 / i - 2 * i* c*0.5 - (+h)*(-c) + c / (0.5*h) - i;
	if (isPrint) cout << "k = c/0.5 * h + 1.0-2*c*0.5-(+h)*(-c) = {7.3,7.3} " << endl;
	if (isPrint) cout << k;
	SASSERT(IsEqual(k[0], 7.3) && IsEqual(k[1], 7.3), "Test Failed!");
	cout << "   OK. \n\n";


	cout << "===========Integer Sarray==============" << endl;
	sarint l(0, 2);
	sarint j = { 10,10 };
	l = 2 * j / 2 - j / (-i) + 3 * j*i + i / 100;
	if (isPrint) cout << "sarint i={1,1},  sarint j={10,10}, sarint l(0,2)" << endl;
	if (isPrint) cout << "l = 2*j/2 - j/(-i) + 3*j*i + i/100" << endl;
	if (isPrint) cout << l;
	SASSERT(l[0] == 50 && l[1] == 50, "Test Failed!");
	cout << "   OK. \n\n";


	cout << "====== Implitcit type casting: Integer * Double =========" << endl;
	if (isPrint) cout << "Sarray handles automatic type promotion of arithmetic operations:" << endl;
	if (isPrint) cout << "c={2.1,2.1}, i={1,1}" << endl;
	if (isPrint) cout << "-----> +operator \n\n";
	if (isPrint) cout << "Type of i+c is " << typeid(i + c).name() << " result =  " << i + c;
	if (isPrint) cout << "Type of c+i is " << typeid(c + i).name() << " result =  " << c + i;
	if (isPrint) cout << "Type of i+1.5 is " << typeid(i + 1.5).name() << " result = " << i + 1.5;
	if (isPrint) cout << "Type of 1.5+i is " << typeid(1.5 + i).name() << " result = " << 1.5 + i;
	SASSERT(typeid(i + c) == typeid(sardouble) && typeid(c + i) == typeid(sardouble) &&
		typeid(i + 1.5) == typeid(sardouble) && typeid(1.5 + i) == typeid(sardouble), "Test Failed!!");
	if (isPrint) cout << "-----> -operator \n\n";
	if (isPrint) cout << "Type of i-c is " << typeid(i - c).name() << " result =  " << i - c;
	if (isPrint) cout << "Type of c-i is " << typeid(c - i).name() << " result =  " << c - i;
	if (isPrint) cout << "Type of i-1.5 is " << typeid(i - 1.5).name() << " result = " << i - 1.5;
	if (isPrint) cout << "Type of 1.5-i is " << typeid(1.5 - i).name() << " result = " << 1.5 - i;
	SASSERT(typeid(i - c) == typeid(sardouble) && typeid(c - i) == typeid(sardouble) &&
		typeid(i - 1.5) == typeid(sardouble) && typeid(1.5 - i) == typeid(sardouble), "Test Failed!!");
	if (isPrint) cout << "-----> *operator \n\n";
	if (isPrint) cout << "Type of i*c is " << typeid(i * c).name() << " result =  " << i * c;
	if (isPrint) cout << "Type of c*i is " << typeid(c * i).name() << " result =  " << c * i;
	if (isPrint) cout << "Type of i*1.5 is " << typeid(i * 1.5).name() << " result = " << i * 1.5;
	if (isPrint) cout << "Type of 1.5*i is " << typeid(1.5 * i).name() << " result = " << 1.5 * i;
	SASSERT(typeid(i * c) == typeid(sardouble) && typeid(c * i) == typeid(sardouble) &&
		typeid(i * 1.5) == typeid(sardouble) && typeid(1.5 * i) == typeid(sardouble), "Test Failed!!");
	if (isPrint) cout << "-----> /operator \n\n";
	if (isPrint) cout << "Type of i/c is " << typeid(i / c).name() << " result =  " << i / c;
	if (isPrint) cout << "Type of c/i is " << typeid(c / i).name() << " result =  " << c / i;
	if (isPrint) cout << "Type of i/1.5 is " << typeid(i / 1.5).name() << " result = " << i / 1.5;
	if (isPrint) cout << "Type of 1.5/i is " << typeid(1.5 / i).name() << " result = " << 1.5 / i;
	SASSERT(typeid(i / c) == typeid(sardouble) && typeid(c / i) == typeid(sardouble) &&
		typeid(i / 1.5) == typeid(sardouble) && typeid(1.5 / i) == typeid(sardouble), "Test Failed!!");
	if (isPrint) cout << "----- \n\n";
	cout << "   OK. \n\n";

	cout << "====== Explicit type casting =========" << endl;
	if (isPrint)cout << "Sarray can be cast to desired type, if similar casting is available for its elements. \n"
		"For example, int -> double is defined by C++ compilers; therefore it is available by  \n"
		"Sarray too.\n";
	if (isPrint)cout << "Sarray<double> c={2.1,2.1}, Sarray<int> i={1,1}" << endl;
	if (isPrint)cout << "(Sarray<double>)i * c = " << (sardouble)i * c;
	if (isPrint)cout << "Sarray<double>(i) * c = " << sardouble(i) * c;
	if (isPrint)cout << "(Sarray<int>)c * i = " << (sarint)c * i;
	if (isPrint)cout << "Sarray<int>(c) * i = " << sarint(c) * i;
	SASSERT(typeid((sardouble)i * c) == typeid(sardouble) && typeid(sardouble(i) * c) == typeid(sardouble) &&
		typeid((sarint)c * i) == typeid(sarint) && typeid(sarint(c) * i) == typeid(sarint), "Test Failed!!");
	cout << "   OK. \n\n";

	cout << "===========Functions==============" << endl;

	cout << " Dot product ..." << endl;
	if (isPrint) cout << " c={3.0,1.5}, i={1,1} " << endl;
	c[0] = 3.0; c[1] = 1.5;
	if (isPrint) cout << "c.dot(i) = " << c.dot(i) << endl;
	if (isPrint) cout << "i.dot(c) = " << i.dot(c) << endl;

	SASSERT(IsEqual(c.dot(i), 4.5), "Test Failed!");
	SASSERT(typeid(c.dot(i)) == typeid(double) && typeid(i.dot(c)) == typeid(double), "Test Failed!");
	cout << "   OK. \n\n";

	cout << "Press Enter to close.\n\n";
	cin.get();

	return 0;
}
