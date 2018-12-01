
// Because of SASSERT checking, compile this file in debug mode.
#include"sarray.h"
#include<cmath>

#define SDEBUG
#include"sdebug.h"

typedef Sarray<double> sardouble;
typedef Sarray<int> sarint;


using namespace std;

bool eq(double a, double b)
{

    double eps = 0.000001;

    if (abs(a-b)>eps)
    {
        return false;
    }

    return true;

}

int main() {

#ifdef NDEBUG
    cout<<"Make sure compile in debug mode. Assert function is used"
          "for assessing the tests";
    return 0;
#endif
    int nD =2;
    bool isPrint=false;
    cout<<"===========Testing Constructors=============="<<endl;
    cout<<"scalar constructor"<<endl;
    sardouble c(5.0,2);
    if (isPrint) cout<<" sardouble c(rhs=5.0,size=2) "<<endl;
    if (isPrint) cout<<c;
    SASSERT(eq(c[0],5.0) && eq(c[1],5.0),"Error");
    SASSERT(c.getSize()==2,"Error");
    cout<<"   OK. \n\n";

    cout<<"array constructor ..."<<endl;
    double* arr= new double[3]{4.0,2.0,1.0};
    sardouble d(arr,3);
    if (isPrint) cout<<"d = arr[2]={4.0,2.0,1.0}"<<endl;
    if (isPrint) cout<<d;
    SASSERT(eq(d[0],4.0) && eq(d[1],2.0) && eq(d[2],1.0),"Error" );
    SASSERT(d.getSize()==3,"Error");
    cout<<"   OK. \n\n";

    cout<<"same type constructor 1 ..."<<endl;
    sardouble e=c;
    if (isPrint) cout<<"sardouble e=c"<<endl;
    if (isPrint) cout<<e;
    SASSERT(eq(e[0],5.0) && eq(e[1],5.0),"Error");
    SASSERT(e.getSize()==2,"Error");
    cout<<"   OK. \n\n";

    cout<<"Same type constructor 2 "<<endl;
    sardouble f(d);
    if (isPrint) cout<<"sardouble f(d)"<<endl;
    if (isPrint) cout<<f;
    SASSERT(eq(f[0],4.0) && eq(f[1],2.0) && eq(f[2],1.0),"Error" );
    SASSERT(d.getSize()==3,"Error");
    cout<<"   OK. \n\n";

    cout<<"List constructor ... "<<endl;
    sardouble g{1.,2.};
    if (isPrint) cout<<"sardouble g = {1.,2.}"<<endl;
    if (isPrint) cout<<g;
    SASSERT(eq(g[0],1.0) && eq(g[1],2.0),"Error");
    SASSERT(g.getSize()==2,"Error");
    cout<<"   OK. \n\n";


    cout<<"===========Assignment=============="<<endl;
    cout<<"Scalar assignment "<<endl;
    c=2.1;
    if (isPrint) cout<<"c=2.1"<<endl;
    if (isPrint) cout<<c;
    SASSERT(eq(c[0],2.1) && eq(c[1],2.1),"Error");
    SASSERT(c.getSize()==2,"Error");
    cout<<"   OK. \n\n";

    cout<<"print same type & size assignment ..."<<endl;
    sardouble m(3);
    m=d;
    if (isPrint) cout<<"sardouble m(3); m=d;"<<endl;
    if (isPrint) cout<<m;
    SASSERT(eq(m[0],4.0) && eq(m[1],2.0) && eq(m[2],1.0),"Error" );
    SASSERT(m.getSize()==3,"Error");
    cout<<"   OK. \n\n";



    cout<<"===========Unary Operations=============="<<endl;
    sardouble un={1.5,-2.5};
    if (isPrint) cout<<"un={1.5,-2.5} "<<endl;
    cout<<"testing operator +un: "<<endl;
    un = (+un);
    if (isPrint) cout<<un;
    SASSERT(eq(un[0],1.5) && eq(un[1],-2.5),"Error" );
    SASSERT(un.getSize()==2,"Error");
    cout<<"   OK. \n\n";

    cout<<"Testing operator -un: "<<endl;
    un = (-un);
    if (isPrint) cout<<un;
    SASSERT(eq(un[0],-1.5) && eq(un[1],2.5),"Error" );
    SASSERT(un.getSize()==2,"Error");
    cout<<"   OK. \n\n";

    cout<<"===========Operators=============="<<endl;
    sardouble h={2.0,2.0};
    if (isPrint) cout<<"Array c = {2.1,2.1}, h={2.,2.} is used below."<<endl;

    cout<<"===========Scalar & array=============="<<endl;
    cout<<"Right hand side + operator ... "<<endl;
    sardouble k(nD);
    k = c+ 2.1;
    if (isPrint) cout<<"k=c+2.1 "<<endl;
    if (isPrint) cout<<k;
    SASSERT(eq(k[0],4.2) && eq(k[1],4.2),"Error");
    SASSERT(k.getSize()==2,"Error");
    cout<<"   OK. \n\n";

    cout<<"Left hand side + operator ... "<<endl;
    k = 2.1+c;
    if (isPrint) cout<<"k=2.1+c "<<endl;
    if (isPrint) cout<<k;
    SASSERT(eq(k[0],4.2) && eq(k[1],4.2),"Error");
    SASSERT(k.getSize()==2,"Error");
    cout<<"   OK. \n\n";

    cout<<"Right hand side - operator ... "<<endl;
    k = c- 2.0;
    if (isPrint) cout<<"k=c-2.0 "<<endl;
    if (isPrint) cout<<k;
    SASSERT(eq(k[0],0.1) && eq(k[1],0.1),"Error");
    SASSERT(k.getSize()==2,"Error");
    cout<<"   OK. \n\n";

    cout<<"Left hand side - operator ... "<<endl;
    k = 2.0-c;
    if (isPrint) cout<<"k=2.0-c "<<endl;
    if (isPrint) cout<<k;
    SASSERT(eq(k[0],-0.1) && eq(k[1],-0.1),"Error");
    SASSERT(k.getSize()==2,"Error");
    cout<<"   OK. \n\n";

    cout<<"Right hand side * operator "<<endl;
    k = c* 2.0;
    if (isPrint) cout<<"k=c*2.0 "<<endl;
    if (isPrint) cout<<k;
    SASSERT(eq(k[0],4.2) && eq(k[1],4.2),"Error");
    SASSERT(k.getSize()==2,"Error");
    cout<<"   OK. \n\n";

    cout<<"Left hand side * operator ..."<<endl;
    k = 2.0*c;
    if (isPrint) cout<<"k=2.0*c "<<endl;
    if (isPrint) cout<<k;
    SASSERT(eq(k[0],4.2) && eq(k[1],4.2),"Error");
    SASSERT(k.getSize()==2,"Error");
    cout<<"   OK. \n\n";

    cout<<"Right hand side / operator ..."<<endl;
    k = c / 21.0;
    if (isPrint) cout<<"k=c/21.0 "<<endl;
    if (isPrint) cout<<k;
    SASSERT(eq(k[0],0.1) && eq(k[1],0.1),"Error");
    SASSERT(k.getSize()==2,"Error");
    cout<<"   OK. \n\n";

    cout<<"Left hand side / operator ..."<<endl;
    k = 0.42/c;
    if (isPrint) cout<<"k=0.42/c "<<endl;
    if (isPrint) cout<<k;
    SASSERT(eq(k[0],0.2) && eq(k[1],0.2),"Error");
    SASSERT(k.getSize()==2,"Error");
    cout<<"   OK. \n\n";

    cout<<"Mix operator ..."<<endl;
    k = k * c / 21.0;
    if (isPrint) cout<<"k=c/21.0 "<<endl;
    if (isPrint) cout<<k;
    SASSERT(eq(k[0],0.02) && eq(k[1],0.02),"Error");
    SASSERT(k.getSize()==2,"Error");
    cout<<"   OK. \n\n";

    cout<<"===========Sarray & Sarray=============="<<endl;
    cout<<" + operator ... "<<endl;
    k = c+ h;
    if (isPrint) cout<<"k=c+h "<<endl;
    if (isPrint) cout<<k;
    SASSERT(eq(k[0],4.1) && eq(k[1],4.1),"Error");
    SASSERT(k.getSize()==2,"Error");
    cout<<"   OK. \n\n";


    cout<<" - operator ..."<<endl;
    k = c- h;
    if (isPrint) cout<<"k=c-h"<<endl;
    if (isPrint) cout<<k;
    SASSERT(eq(k[0],0.1) && eq(k[1],0.1),"Error");
    SASSERT(k.getSize()==2,"Error");
    cout<<"   OK. \n\n";


    cout<<" * operator ..."<<endl;
    k = c*h;
    if (isPrint) cout<<"k=c*h"<<endl;
    if (isPrint) cout<<k;
    SASSERT(eq(k[0],4.2) && eq(k[1],4.2),"Error");
    SASSERT(k.getSize()==2,"Error");
    cout<<"   OK. \n\n";

    cout<<" / operator ..."<<endl;
    if (isPrint) cout<<"k=c/h"<<endl;
    k = c / h;
    if (isPrint) cout<<k;
    SASSERT(eq(k[0],1.05) && eq(k[1],1.05),"Error");
    SASSERT(k.getSize()==2,"Error");
    cout<<"   OK. \n\n";


    cout<<"===========Sarray & Scalar & Sarray=============="<<endl;
    cout<<"Mix operator ..."<<endl;
    k = c/2.0 * h + 1.0 - 2*c*0.5 - (+h)*(-c) + c/(0.5*h) ;
    if (isPrint) cout<<"k = c/0.5 * h + 1.0-2*c*0.5-(+h)*(-c) = {7.3,7.3} "<<endl;
    if (isPrint) cout<<k;
    SASSERT(eq(k[0],7.3) && eq(k[1],7.3),"Error");
    cout<<"   OK. \n\n";


    cout<<"===========Integer Sarray=============="<<endl;
    sarint i={1,1};
    sarint j={10,10};
    sarint l(0,2);
    l = 2*j/2 - j/(-i) + 3*j*i + i/100;
    if (isPrint) cout<<"sarint i={1,1},  sarint j={10,10}, sarint l(0,2)"<<endl;
    if (isPrint) cout<<"l = 2*j/2 - j/(-i) + 3*j*i + i/100"<<endl;
    if(isPrint) cout<<l;
    SASSERT(l[0]==50 && l[1]==50,"Error");
    cout<<"   OK. \n\n";


    cout<<"====== Implitcit type casting: Integer * Double ========="<<endl;
    if (!isPrint) cout<<"\nSwitch on isPrint variable to see the results of this test.\n"<<endl;
    if (isPrint) cout<<"Sarray result of mix types is cast by left hand side type."<<endl;
    if (isPrint) cout<<"c={2.1,2.1}, i={1,1}"<<endl;
    if (isPrint) cout<<"i*c = "<< i*c;
    if (isPrint) cout<<"c*i = "<< c*i;

    cout<<"====== Explitcit type casting ========="<<endl;
    if (!isPrint) cout<<"\nSwitch on isPrint variable to see the results of this test.\n"<<endl;
    if (isPrint)cout<<"Sarray can be cast to desired type, if similar casting is available for its elements. \n"
          "For example, int -> double is defined by C++ compilers; therefore it is available by  \n"
          "Sarray too.\n";
    if (isPrint)cout<<"Sarray<double> c={2.1,2.1}, Sarray<int> i={1,1}"<<endl;
    if (isPrint)cout<<"(Sarray<double>)i * c = "<< (sardouble)i * c;
    if (isPrint)cout<<"Sarray<double>(i) * c = "<< sardouble(i) * c;
    if (isPrint)cout<<"(Sarray<int>)c * i = "<< (sarint)c * i;
    if (isPrint)cout<<"Sarray<int>(c) * i = "<< sarint(c) * i;

    cout<<"===========Functions=============="<<endl;

    cout<<" Dot product ..."<<endl;
    if (isPrint) cout<<" c={3.0,1.5}, i={1,1} "<<endl;
    c[0]=3.0;c[1]=1.5;
    double r = c.dot(i);
    if (isPrint) cout<< "c.dot(i) = "<<r<<endl;
    if (isPrint) cout<<" Note: answer is double because left hand side of dot product is double.\n"
                       "See Explicit Casting to change this."<<endl;

    SASSERT(eq(r,4.5),"Error");
    cout<<"   OK. \n\n";

	cout << "Press Enter to close.\n\n";
	cin.get();

    return 0;
}
