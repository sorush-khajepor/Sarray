#include"sarray.h"
typedef Sarray<double> sardouble;
typedef Sarray<int> sarint;


using namespace std;

int main() {

    int nD =2;
    cout<<"===========Testing Constructors=============="<<endl;
    cout<<"scalar constructor : sardouble c(rhs=5.0,size=2) "<<endl;
    sardouble c(5.0,2);
    cout<<c;

    cout<<"array constructor d = arr[2]={4.0,2.0,1.0}"<<endl;
    double* arr= new double[3]{4.0,2.0,1.0};
    sardouble d(arr,3);
    cout<<d;

    cout<<"same type constructor1 : sardouble e=c"<<endl;
    sardouble e=c;
    cout<<e;

    cout<<"Same type constructor2 : sardouble f(d)"<<endl;
    sardouble f(d);
    cout<<f;

    cout<<"List constructor:  sardouble g = {1.,2.}"<<endl;
    sardouble g{1.,2.};
    cout<<g;


    cout<<"===========Assignment=============="<<endl;
    cout<<"Scalar assignment c=2.1"<<endl;
    c=2.1;
    cout<<c;
    
    cout<<"print same type & size assignment :sardouble m(3); m=d;"<<endl;
    sardouble m(3);
    m=d;
    cout<<m;


    cout<<"===========Operators=============="<<endl;
    sardouble h={2.0,2.0};
    cout<<"Array c = {2.1,2.1}, h={2.,2.} is used below."<<endl;


    cout<<"===========Scalar & array=============="<<endl;
    cout<<"Right hand side + operator k=c+2.1 "<<endl;
    sardouble k(nD);
    k = c+ 2.1;
    cout<<k;

    cout<<"Left hand side + operator k=2.1+c "<<endl;
    k = 2.1+c;
    cout<<k;

    cout<<"Right hand side - operator k=c-2.0 "<<endl;
    k = c- 2.0;
    cout<<k;

    cout<<"Left hand side - operator k=2.0-c "<<endl;
    k = 2.0-c;
    cout<<k;

    cout<<"Right hand side * operator k=c*2.0 "<<endl;
    k = c* 2.0;
    cout<<k;

    cout<<"Left hand side * operator k=2.0*c "<<endl;
    k = 2.0*c;
    cout<<k;

    cout<<"Right hand side / operator k=c/21.0 "<<endl;
    k = c / 21.0;
    cout<<k;

    cout<<"Left hand side / operator k=0.42/c "<<endl;
    k = 0.42/c;
    cout<<k;

    cout<<"Mix operator k=c/21.0 "<<endl;
    k = k * c / 21.0;
    cout<<k;

    cout<<"===========Sarray & Sarray=============="<<endl;
    cout<<" + operator k=c+h "<<endl;
    k = c+ h;
    cout<<k;


    cout<<" - operator k=c-h"<<endl;
    k = c- h;
    cout<<k;


    cout<<" * operator k=c*h"<<endl;
    k = c*h;
    cout<<k;

    cout<<" / operator k=c/h"<<endl;
    k = c / h;
    cout<<k;


    cout<<"===========Sarray & Scalar & Sarray=============="<<endl;
    cout<<"Mix operator k = c/0.5 * h + 1.0-2*c-h*c = {-5.3,-5.3} "<<endl;
    k = c/2.0 * h + 1.0-2*c-h*c;
    cout<<k;
// Unary interaction like a*(-c) is not defined.

/*
    cout<<"print / operator k=1/c "<<endl;
    k = 1/c;
    cout<<k;

    cout<<"print sum funtion : c.sum() "<<endl;
    cout<<"sum="<<c.sum()<<endl;


    cout<<"print list constructor :sarint g={1,2}"<<endl;
    sarint g={1,2};
    cout<<g;

   // Here order of operation is important. 
    cout<<"print dot product d.dot(g) (int=>double)"<<endl;
    cout<<d.dot(g)<<endl;
    cout<<"print dot product g.dot(d) (double=>int)"<<endl;
    cout<<g.dot(d)<<endl;

    cout<<"print int-double-number, type conversion operation, sardouble h = (sardouble)g*2+d/2-c/2.1={2.95,395}"<<endl;
    sardouble h =(sardouble) g*2+d/2-c/2.0;
    cout<<h;
 */   

    return 0;
}
