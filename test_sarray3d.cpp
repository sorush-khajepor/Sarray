#include"sarray3d.h"
typedef Sarray3D<double> sardouble3d;
typedef Sarray3D<int> sarint3d;


using namespace std;

int main() {

    int nD =2;
    int nQ = 9;
    cout<<"===========Testing ArrayND=============="<<endl;
    cout<<" sardouble c(2,2,2)  "<<endl;
    sardouble3d c(2,2,2);
    c = 100.0;
    cout<<c;

    sardouble3d d(8,1,1);
    d = c;
    
    cout<<" d=c   "<<endl;
    cout<<d;


    sardouble3d e(4,2,1);
    e = (c+d);
    
    cout<<" e = c+d   "<<endl;
    cout<<e;

    sardouble3d f(4,2,1);
    f = 1/c;
    
    cout<<" f=1/c   "<<endl;
    cout<<f;
    return 0;
}
