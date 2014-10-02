#include "class_Polynom.h"

using namespace std;

int main()
{
    int P;
    cout<<"Enter the size of Polynoms:  "<<endl;
    cin>>P;

    Polynom f(P);
    Polynom g(P);

    cin>>f;
    cin>>g;

    cout<<f<<endl;
    cout<<g<<endl;

    cout<<"Addition of Polynoms:"<<endl;
    cout<<f+g<<endl;

    cout<<"Subtraction of Polynoms:"<<endl;
    cout<<f-g<<endl;

    cout<<"Multiplication of the first Polynom and number"<<endl;
    cout<<f*10<<endl;

    cout<<"Multiplication of the second Polynom and number"<<endl;
    cout<<g*10<<endl;

    cout<<"Value of the first Polynom: "<<endl;
    f.FindValueOfPolynom();
    cout<<endl;

    cout<<"Value of the second Polynom: "<<endl;
    g.FindValueOfPolynom();

    return 0;
}
