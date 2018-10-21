#include"sarray.h"
#include <stdlib.h>
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

    int nD =2;
    bool isPrint=true;
    cout<<"===========Testing Constructors=============="<<endl;
    cout<<"scalar constructor : sardouble c(rhs=5.0,size=2) "<<endl;
    sardouble c(5.0,2);
    if (isPrint) cout<<c;
    assert(eq(c[0],5.0) && eq(c[1],5.0));
    assert(c.getSize()==2);

    cout<<"array constructor d = arr[2]={4.0,2.0,1.0}"<<endl;
    double* arr= new double[3]{4.0,2.0,1.0};
    sardouble d(arr,3);
    if (isPrint) cout<<d;
    assert(eq(d[0],4.0) && eq(d[1],2.0) && eq(d[2],1.0) );
    assert(d.getSize()==3);

    cout<<"same type constructor1 : sardouble e=c"<<endl;
    sardouble e=c;
    if (isPrint) cout<<e;
    assert(eq(e[0],5.0) && eq(e[1],5.0));
    assert(e.getSize()==2);

    cout<<"Same type constructor2 : sardouble f(d)"<<endl;
    sardouble f(d);
    if (isPrint) cout<<f;
    assert(eq(f[0],4.0) && eq(f[1],2.0) && eq(f[2],1.0) );
    assert(d.getSize()==3);

    cout<<"List constructor:  sardouble g = {1.,2.}"<<endl;
    sardouble g{1.,2.};
    if (isPrint) cout<<g;
    assert(eq(g[0],1.0) && eq(g[1],2.0));
    assert(g.getSize()==2);


    cout<<"===========Assignment=============="<<endl;
    cout<<"Scalar assignment c=2.1"<<endl;
    c=2.1;
    if (isPrint) cout<<c;
    assert(eq(c[0],2.1) && eq(c[1],2.1));
    assert(c.getSize()==2);
    
    cout<<"print same type & size assignment :sardouble m(3); m=d;"<<endl;
    sardouble m(3);
    m=d;
    if (isPrint) cout<<m;
    assert(eq(m[0],4.0) && eq(m[1],2.0) && eq(m[2],1.0) );
    assert(m.getSize()==3);



    cout<<"===========Unary Operations=============="<<endl;
    sardouble un={1.5,-2.5};
    cout<<"un={1.5,-2.5}. testing operator +un: "<<endl;
    un = (+un);
    if (isPrint) cout<<un;
    assert(eq(un[0],1.5) && eq(un[1],-2.5) );
    assert(un.getSize()==2);

    cout<<"Testing operator -un: "<<endl;
    un = (-un);
    if (isPrint) cout<<un;
    assert(eq(un[0],-1.5) && eq(un[1],2.5) );
    assert(un.getSize()==2);

    cout<<"===========Operators=============="<<endl;
    sardouble h={2.0,2.0};
    cout<<"Array c = {2.1,2.1}, h={2.,2.} is used below."<<endl;

    cout<<"===========Scalar & array=============="<<endl;
    cout<<"Right hand side + operator k=c+2.1 "<<endl;
    sardouble k(nD);
    k = c+ 2.1;
    if (isPrint) cout<<k;
    assert(eq(k[0],4.2) && eq(k[1],4.2));
    assert(k.getSize()==2);

    cout<<"Left hand side + operator k=2.1+c "<<endl;
    k = 2.1+c;
    if (isPrint) cout<<k;
    assert(eq(k[0],4.2) && eq(k[1],4.2));
    assert(k.getSize()==2);

    cout<<"Right hand side - operator k=c-2.0 "<<endl;
    k = c- 2.0;
    if (isPrint) cout<<k;
    assert(eq(k[0],0.1) && eq(k[1],0.1));
    assert(k.getSize()==2);

    cout<<"Left hand side - operator k=2.0-c "<<endl;
    k = 2.0-c;
    if (isPrint) cout<<k;
    assert(eq(k[0],-0.1) && eq(k[1],-0.1));
    assert(k.getSize()==2);

    cout<<"Right hand side * operator k=c*2.0 "<<endl;
    k = c* 2.0;
    if (isPrint) cout<<k;
    assert(eq(k[0],4.2) && eq(k[1],4.2));
    assert(k.getSize()==2);

    cout<<"Left hand side * operator k=2.0*c "<<endl;
    k = 2.0*c;
    if (isPrint) cout<<k;
    assert(eq(k[0],4.2) && eq(k[1],4.2));
    assert(k.getSize()==2);

    cout<<"Right hand side / operator k=c/21.0 "<<endl;
    k = c / 21.0;
    if (isPrint) cout<<k;
    assert(eq(k[0],0.1) && eq(k[1],0.1));
    assert(k.getSize()==2);

    cout<<"Left hand side / operator k=0.42/c "<<endl;
    k = 0.42/c;
    if (isPrint) cout<<k;
    assert(eq(k[0],0.2) && eq(k[1],0.2));
    assert(k.getSize()==2);

    cout<<"Mix operator k=c/21.0 "<<endl;
    k = k * c / 21.0;
    if (isPrint) cout<<k;
    assert(eq(k[0],0.02) && eq(k[1],0.02));
    assert(k.getSize()==2);

    cout<<"===========Sarray & Sarray=============="<<endl;
    cout<<" + operator k=c+h "<<endl;
    k = c+ h;
    if (isPrint) cout<<k;
    assert(eq(k[0],4.1) && eq(k[1],4.1));
    assert(k.getSize()==2);


    cout<<" - operator k=c-h"<<endl;
    k = c- h;
    if (isPrint) cout<<k;
    assert(eq(k[0],0.1) && eq(k[1],0.1));
    assert(k.getSize()==2);


    cout<<" * operator k=c*h"<<endl;
    k = c*h;
    if (isPrint) cout<<k;
    assert(eq(k[0],4.2) && eq(k[1],4.2));
    assert(k.getSize()==2);

    cout<<" / operator k=c/h"<<endl;
    k = c / h;
    if (isPrint) cout<<k;
    assert(eq(k[0],1.05) && eq(k[1],1.05));
    assert(k.getSize()==2);


    cout<<"===========Sarray & Scalar & Sarray=============="<<endl;
    cout<<"Mix operator k = c/0.5 * h + 1.0-2*c*0.5-(+h)*(-c) = {7.3,7.3} "<<endl;
    k = c/2.0 * h + 1.0 - 2*c*0.5 - (+h)*(-c) + c/(0.5*h) ;
    if (isPrint) cout<<k;
    assert(eq(k[0],7.3) && eq(k[1],7.3));

    
    cout<<"===========Integer Sarray=============="<<endl;
    sarint i={1,1};
    sarint j={10,10};
    sarint l(0,2);

    l = 2*j/2 - j/(-i) + 3*j*i + i/100;
    if(isPrint) cout<<l;
    assert(l[0]==50 && l[1]==50);
    
    cout<<"===========Integer * Double=============="<<endl;
    cout<<"c={2.1,2.1}, i={1,1}. Sarray result of mix types is set by left hand side type."<<endl;
    cout<<"i*c = "<< i*c;
    cout<<"c*i = "<< c*i;

    return 0;
    


}
