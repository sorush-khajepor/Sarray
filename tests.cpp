
/*
Unit tests for Sarray<T> class
*/

// Activates SASSERT which is used for assertion of tests
#define SDEBUG

// Using Sarray library
#include"sarray.h"

// This is added to use absolute function, abs().
#include<cmath>

// This is added to implement typeid() function which shows
// the dynamic type of objects.
#include <typeinfo>

// Some lazy typing
typedef Sarray<double, 3> Sardouble;
typedef Sarray<int, 3> Sarint;

typedef Sarray<double, 2> Sardouble2d;
typedef Sarray<int, 2> Sarint2d;

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
	// Make it false to see less on screen.
	bool isPrint = true;

	cout << "===========Testing Constructors==============" << endl;
	cout << "scalar constructor" << endl;
	{
		Sardouble a({5.0, 2, 1});
		if (isPrint) cout << " Sardouble a(value=5.0, size=2) " << endl;
		if (isPrint) cout << a;
		SASSERT(IsEqual(a[0], 5.0) && IsEqual(a[1], 2.0)&& IsEqual(a[2], 1.0), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "Construct with an array ..." << endl;
	{
		double* array = new double[3]{ 4.0,2.0,1.0 };
		Sardouble a(array);
		if (isPrint) cout << "a = array[2]={4.0,2.0,1.0}" << endl;
		if (isPrint) cout << a;
		SASSERT(IsEqual(a[0], 4.0) && IsEqual(a[1], 2.0) && IsEqual(a[2], 1.0), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}
	cout << "Construct with assignment of same-type object ..." << endl;
	{
		Sardouble a({5, 2, 1});
		auto b = a;
		if (isPrint) cout << "Sardouble b = a" << endl;
		if (isPrint) cout << b;
		SASSERT(IsEqual(b[0], 5.0) && IsEqual(b[1], 2.0)&& IsEqual(b[2], 1.0), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}


	cout << "Construct with same-type object ... " << endl;
	{
		Sardouble a(new double[3]{ 4.0,2.0,1.0 });
		Sardouble b(a);
		if (isPrint) cout << "Sardouble b(a)" << endl;
		if (isPrint) cout << b;
		SASSERT(IsEqual(b[0], 4.0) && IsEqual(b[1], 2.0) && IsEqual(b[2], 1.0), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "===========Assignment==============" << endl;
	cout << "Scalar assignment " << endl;
	{
		Sardouble a({ 0.,0.,0. });
		a = 2.1;
		if (isPrint) cout << "a=2.1" << endl;
		if (isPrint) cout << a;
		SASSERT(IsEqual(a[0], 2.1) && IsEqual(a[1], 2.1)&& IsEqual(a[2], 2.1), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "Same type & size assignment ..." << endl;
	{
		Sardouble a(3);
		Sardouble b{ 4.0,2.0,1.0 };
		a = b;
		if (isPrint) cout << "Sardouble a(3); Sardouble b{4.0 ,2.0 , 1.0}; a = b;" << endl;
		if (isPrint) cout << a;
		SASSERT(IsEqual(a[0], 4.0) && IsEqual(a[1], 2.0) && IsEqual(a[2], 1.0), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "===========Unary Operations==============" << endl;
	cout << "testing operator positive (+)... " << endl;
	{
		if (isPrint) cout << "a={1.5,-2.5}, a = (+a) :" << endl;
		Sardouble2d a = { 1.5,-2.5 };
		a = (+a);
		if (isPrint) cout << a;
		SASSERT(IsEqual(a[0], 1.5) && IsEqual(a[1], -2.5), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "Testing operator Negative... " << endl;
	{
		if (isPrint) cout << "a={1.5,-2.5}, a = (-a) :" << endl;
		Sardouble2d a = { 1.5,-2.5 };
		a = (-a);
		if (isPrint) cout << a;
		SASSERT(IsEqual(a[0], -1.5) && IsEqual(a[1], 2.5), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "=========== Scalar array operators ==============" << endl;

	cout << "Right hand side + operator ... " << endl;
	{
		if (isPrint) cout << "Sardouble b = {2.1,2.1}, Sardouble a(2) are used below." << endl;
		Sardouble2d a(2);
		Sardouble2d b{ 2.1,2.1 };
		a = b + 2.1;
		if (isPrint) cout << "a = b + 2.1 " << endl;
		if (isPrint) cout << a;
		SASSERT(IsEqual(a[0], 4.2) && IsEqual(a[1], 4.2), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "Left hand side + operator ... " << endl;
	{
		if (isPrint) cout << "Sardouble b = {2.1, 2.1}, Sardouble a={2.1, 2.1} are used below." << endl;
		Sardouble2d a{ 2.1, 2.1 };
		Sardouble2d b{ 2.1, 2.1 };
		a = 2.1 + b;
		if (isPrint) cout << "a = 2.1 + b " << endl;
		if (isPrint) cout << a;
		SASSERT(IsEqual(a[0], 4.2) && IsEqual(a[1], 4.2), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "Right hand side - operator ... " << endl;
	{
		if (isPrint) cout << "Sardouble b = {2.1,2.1}, Sardouble a(2) are used below." << endl;
		Sardouble2d a(2);
		Sardouble2d b{ 2.1, 2.1 };
		a = b - 2.0;
		if (isPrint) cout << "a = b - 2.0 " << endl;
		if (isPrint) cout << a;
		SASSERT(IsEqual(a[0], 0.1) && IsEqual(a[1], 0.1), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "Left hand side - operator ... " << endl;
	{
		if (isPrint) cout << "Sardouble b = {2.1,2.1}, Sardouble a(2) are used below." << endl;
		Sardouble2d a(2);
		Sardouble2d b{ 2.1, 2.1 };
		a = 2.0 - b;
		if (isPrint) cout << "a = 2.0 - b " << endl;
		if (isPrint) cout << a;
		SASSERT(IsEqual(a[0], -0.1) && IsEqual(a[1], -0.1), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "Right hand side * operator " << endl;
	{
		if (isPrint) cout << "Sardouble b = {2.1,2.1}, Sardouble a(2) are used below." << endl;
		Sardouble2d a(2);
		Sardouble2d b{ 2.1, 2.1 };
		a = b * 2.0;
		if (isPrint) cout << "a = b * 2.0 " << endl;
		if (isPrint) cout << a;
		SASSERT(IsEqual(a[0], 4.2) && IsEqual(a[1], 4.2), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "Left hand side * operator ..." << endl;
	{
		if (isPrint) cout << "Sardouble b = {2.1,2.1}, Sardouble a(2) are used below." << endl;
		Sardouble2d a(2);
		Sardouble2d b{ 2.1, 2.1 };
		a = 2.0*b;
		if (isPrint) cout << "a = 2.0 * b " << endl;
		if (isPrint) cout << a;
		SASSERT(IsEqual(a[0], 4.2) && IsEqual(a[1], 4.2), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "Right hand side / operator ..." << endl;
	{
		if (isPrint) cout << "Sardouble c = {2.1,2.1}, Sardouble k(2) are used below." << endl;
		Sardouble2d k(2);
		Sardouble2d c{ 2.1, 2.1 };
		k = c / 21.0;
		if (isPrint) cout << "k=c/21.0 " << endl;
		if (isPrint) cout << k;
		SASSERT(IsEqual(k[0], 0.1) && IsEqual(k[1], 0.1), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "Left hand side / operator ..." << endl;
	{
		if (isPrint) cout << "Sardouble b = {2.1,2.1}, Sardouble a(2) are used below." << endl;
		Sardouble2d a(2);
		Sardouble2d b{ 2.1, 2.1 };
		a = 0.42 / b;
		if (isPrint) cout << "a = 0.42 / b " << endl;
		if (isPrint) cout << a;
		SASSERT(IsEqual(a[0], 0.2) && IsEqual(a[1], 0.2), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "Mix operator ..." << endl;
	{
		if (isPrint) cout << "Sardouble b = {2.1,2.1}, Sardouble a(2) are used below." << endl;
		Sardouble2d a{ 0.2, 0.2 };
		Sardouble2d b{ 2.1, 2.1 };
		a = a * b / 21.0;
		if (isPrint) cout << "a = a * b / 21.0 " << endl;
		if (isPrint) cout << a;
		SASSERT(IsEqual(a[0], 0.02) && IsEqual(a[1], 0.02), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "=========== Sarray Sarray Operations ==============" << endl;
	if (isPrint) cout << "\nArray c = {2.1,2.1}, h={2.,2.} is used below." << endl;
	cout << " + operator ... " << endl;
	{
		if (isPrint) cout << "\n a = {2.1,2.1}, b={2.,2.} are used below." << endl;
		Sardouble2d c(2);
		Sardouble2d b({2.0, 2});
		Sardouble2d a{ 2.1, 2.1 };
		c = a + b;
		if (isPrint) cout << "c = a + b " << endl;
		if (isPrint) cout << c;
		SASSERT(IsEqual(c[0], 4.1) && IsEqual(c[1], 4.1), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}
	cout << " - operator ..." << endl;
	{
		if (isPrint) cout << "\n a = {2.1,2.1}, b = {2.0, 2.0} are used below." << endl;
		Sardouble2d c(2);
		Sardouble2d b({2.0, 2});
		Sardouble2d a{ 2.1, 2.1 };
		c = a - b;
		if (isPrint) cout << "c = a - b" << endl;
		if (isPrint) cout << c;
		SASSERT(IsEqual(c[0], 0.1) && IsEqual(c[1], 0.1), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << " * operator ..." << endl;
	{
		if (isPrint) cout << "\n a = {2.1,2.1}, b={2.0, 2.0} are used below." << endl;
		Sardouble2d a{ 2.1, 2.1 };
		Sardouble2d b({2.0, 2});
		Sardouble2d c(2);
		c = a * b;
		if (isPrint) cout << "c = a * b" << endl;
		if (isPrint) cout << c;
		SASSERT(IsEqual(c[0], 4.2) && IsEqual(c[1], 4.2), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}
	cout << " / operator ..." << endl;
	{
		if (isPrint) cout << "\n a = {2.1,2.1}, b={2.,2.} are used below." << endl;
		Sardouble2d a{ 2.1, 2.1 };
		Sardouble2d b(2.0);
		Sardouble2d c(2);
		if (isPrint) cout << "c = a / b" << endl;
		c = a / b;
		if (isPrint) cout << c;
		SASSERT(IsEqual(c[0], 1.05) && IsEqual(c[1], 1.05), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "=========== Sarray-Scalar-Sarray (double-int) Mix Operation ==============\n\n" << endl;
	if (isPrint) cout << "Sarray<double> c = {2.1,2.1}, h={2.0,2.0}, and Sarray<int> i={1,1} are used below." << endl;

	cout << "Mix operator ..." << endl;
	{
		if (isPrint) cout << "Sarray<double> a = {2.1,2.1}, b={2.0,2.0}, and Sarray<int> i={1,1} are used below." << endl;
		Sardouble2d c(2);
		Sardouble2d a{ 2.1, 2.1 };
		Sardouble2d b{ 2.0, 2.0 };
		Sarint2d i = { 1,1 };
		c = i + a / 2.0 * b*i + 1.0 / i - 2 * i* a*0.5 - (+b)*(-a) + a / (0.5*b) - i;
		if (isPrint) cout << "k = c/0.5 * h + 1.0-2*c*0.5-(+h)*(-c) = {7.3,7.3} " << endl;
		if (isPrint) cout << c;
		SASSERT(IsEqual(c[0], 7.3) && IsEqual(c[1], 7.3), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "===========Integer Sarray Sarray Mix Operations ==============" << endl;
	{
		if (isPrint) cout << "Sarray<int> j = {10,10} and Sarray<int> i={1,1} are used below." << endl;
		Sarint2d l(0);
		Sarint2d j = { 10,10 };
		Sarint2d i = { 1,1 };
		l = 2 * j / 2 - j / (-i) + 3 * j*i + i / 100;
		if (isPrint) cout << "sarint i={1,1},  sarint j={10,10}, sarint l(0,2)" << endl;
		if (isPrint) cout << "l = 2*j/2 - j/(-i) + 3*j*i + i/100" << endl;
		if (isPrint) cout << l;
		SASSERT(l[0] == 50 && l[1] == 50, "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "====== Implicit type casting: Integer * Double =========" << endl;

	if (isPrint) cout << "Note: Sarray handles automatic type promotion of arithmetic operations:" << endl;

	cout << "-----> +operator \n\n";
	{
		if (isPrint) cout << "a = {2.1,2.1}, i={1,1}" << endl;
		Sardouble2d a{ 2.1, 2.1 };
		Sarint2d i = { 1,1 };
		if (isPrint) cout << "Type of i + a is " << typeid(i + a).name() << " result =  " << i + a;
		if (isPrint) cout << "Type of a + i is " << typeid(a + i).name() << " result =  " << a + i;
		if (isPrint) cout << "Type of i + 1.5 is " << typeid(i + 1.5).name() << " result = " << i + 1.5;
		if (isPrint) cout << "Type of 1.5 + i is " << typeid(1.5 + i).name() << " result = " << 1.5 + i;
		SASSERT(typeid(i + a) == typeid(Sardouble2d) && typeid(a + i) == typeid(Sardouble2d) &&
			typeid(i + 1.5) == typeid(Sardouble2d) && typeid(1.5 + i) == typeid(Sardouble2d), "Test Failed!!");
	}

	cout << "-----> -operator \n\n";
	{
		if (isPrint) cout << "a = {2.1, 2.1}, i={1, 1}" << endl;
		Sardouble2d a{ 2.1, 2.1 };
		Sarint2d i = { 1,1 };
		if (isPrint) cout << "Type of i - a is " << typeid(i - a).name() << " result =  " << i - a;
		if (isPrint) cout << "Type of a - i is " << typeid(a - i).name() << " result =  " << a - i;
		if (isPrint) cout << "Type of i - 1.5 is " << typeid(i - 1.5).name() << " result = " << i - 1.5;
		if (isPrint) cout << "Type of 1.5 - i is " << typeid(1.5 - i).name() << " result = " << 1.5 - i;
		SASSERT(typeid(i - a) == typeid(Sardouble2d) && typeid(a - i) == typeid(Sardouble2d) &&
			typeid(i - 1.5) == typeid(Sardouble2d) && typeid(1.5 - i) == typeid(Sardouble2d), "Test Failed!!");
	}

	cout << "-----> * operator \n\n";
	{
		if (isPrint) cout << "a = {2.1, 2.1}, i = {1, 1}" << endl;
		Sardouble2d a{ 2.1, 2.1 };
		Sarint2d i = { 1,1 };
		if (isPrint) cout << "Type of i * a is " << typeid(i * a).name() << " result =  " << i * a;
		if (isPrint) cout << "Type of a * i is " << typeid(a * i).name() << " result =  " << a * i;
		if (isPrint) cout << "Type of i * 1.5 is " << typeid(i * 1.5).name() << " result = " << i * 1.5;
		if (isPrint) cout << "Type of 1.5 * i is " << typeid(1.5 * i).name() << " result = " << 1.5 * i;
		SASSERT(typeid(i * a) == typeid(Sardouble2d) && typeid(a * i) == typeid(Sardouble2d) &&
			typeid(i * 1.5) == typeid(Sardouble2d) && typeid(1.5 * i) == typeid(Sardouble2d), "Test Failed!!");
	}

	cout << "-----> / operator \n\n";
	{
		if (isPrint) cout << "a = {2.1, 2.1}, i = {1, 1}" << endl;
		Sardouble2d a{ 2.1, 2.1 };
		Sarint2d i = { 1,1 };
		if (isPrint) cout << "Type of i / a is " << typeid(i / a).name() << " result =  " << i / a;
		if (isPrint) cout << "Type of a / i is " << typeid(a / i).name() << " result =  " << a / i;
		if (isPrint) cout << "Type of i/1.5 is " << typeid(i / 1.5).name() << " result = " << i / 1.5;
		if (isPrint) cout << "Type of 1.5/i is " << typeid(1.5 / i).name() << " result = " << 1.5 / i;
		SASSERT(typeid(i / a) == typeid(Sardouble2d) && typeid(a / i) == typeid(Sardouble2d) &&
			typeid(i / 1.5) == typeid(Sardouble2d) && typeid(1.5 / i) == typeid(Sardouble2d), "Test Failed!!");
		if (isPrint) cout << "----- \n\n";
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "====== Explicit type casting =========" << endl;
	{
		if (isPrint)cout << "Sarray can be cast to desired type, if similar casting is available for its elements. \n"
			"For example, int -> double is defined by C++ compilers; therefore it is available by  \n"
			"Sarray too.\n";
		if (isPrint)cout << "Sarray<double> a = {2.1, 2.1}, Sarray<int> i = {1, 1}" << endl;
		Sardouble2d a{ 2.1, 2.1 };
		Sarint2d i = { 1,1 };
		if (isPrint)cout << "(Sarray<double>)i * a = " << (Sardouble2d)i * a;
		if (isPrint)cout << "Sarray<double>(i) * a = " << Sardouble2d(i) * a;
		if (isPrint)cout << "(Sarray<int>)a * i = " << (Sarint2d)a * i;
		if (isPrint)cout << "Sarray<int>(a) * i = " << Sarint2d(a) * i;
		SASSERT(typeid((Sardouble2d)i * a) == typeid(Sardouble2d) && typeid(Sardouble2d(i) * a) == typeid(Sardouble2d) &&
			typeid((Sarint2d)a * i) == typeid(Sarint2d) && typeid(Sarint2d(a) * i) == typeid(Sarint2d), "Test Failed!!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout << "===========Functions==============\n\n" << endl;

	cout << " Dot product ..." << endl;
	{

		if (isPrint) cout << " a={3.0, 1.5}, i={1, 1} " << endl;
		Sardouble2d a{ 3.0, 1.5 };
		Sarint2d i = { 1, 1 };
		if (isPrint) cout << "a.dot(i) = " << a.dot(i) << endl;
		if (isPrint) cout << "i.dot(a) = " << i.dot(a) << endl;
		SASSERT(IsEqual(a.dot(i), 4.5), "Test Failed!");
		SASSERT(typeid(a.dot(i)) == typeid(double) && typeid(i.dot(a)) == typeid(double), "Test Failed!");
		cout << "~~~ Test Passed! ~~~ \n\n";
	}

	cout<< "All test were successful."<<endl;

	return 0;
}
