#include <iostream>
#include <cmath>
#include <algorithm>
#include "class_Polynom.h"

using namespace std;

Polynom::Polynom(int n)
{
    this->n=n;
    P = new int[n];
    for(int i = 0; i < n; i++)
    {
        P[i] = 0;
    }
}

Polynom::Polynom(Polynom & SecondP)
{
    n = SecondP.n;
    P = new int[n];
    for(int i = 0; i < n; i++)
    {
        P[i] = SecondP[i];
    }
}

void Polynom::FindValueOfPolynom(int x)
{
    int x;
    cout<<"Enter the value of variable x ";
    cin>>x;
    this->x=x;
    int s=P[n-1];
    for(int i=n-2; i>=0; i--)
        s=s+P[i]*pow(x,i);
}

Polynom Polynom::operator*(int x)
{
    Polynom a(n);
    for(int i = 0; i < n; i++)
    {
        a[i] = P[i] * x;
    }
    return a;
}

Polynom Polynom::operator+(Polynom & SecondP)
{
    int k=std::max(n,SecondP.n);
    Polynom s(k);
    for(int i = 0; i <SecondP.n; i++)
    {
        s[i] += SecondP[i];
    }
    for(int i = 0; i <n; i++)
    {
        s[i] += P[i];
    }
    return s;
}

Polynom Polynom::operator-(Polynom & SecondP)
{
    int k=std::max(n,SecondP.n);
    Polynom raznost(k);
    for(int i = 0; i <SecondP.n; i++)
    {
        raznost[i] -=  SecondP[i];
    }
    for(int i = 0; i <n; i++)
    {
        raznost[i] += P[i];
    }
    return raznost;
}

Polynom & Polynom::operator=( Polynom & SecondP)
{
    if (this != &SecondP)
    {
        delete [] P;
        n = SecondP.n;
        P = new int[n+1];
        for(int i = 0; i <=n; i++)
        {
            P[i] = SecondP[i];
        }
    }
    return *this;
}

ostream & operator<<(ostream & mystream, Polynom &SecondP)
{
    int k=SecondP.DimensionOfPoly();
    if(k)
    {
        mystream<<'('<<SecondP[0]<<")x^"<<k-1;
        for(int l=k-2, i = 1; i<k; i++,l--)
        {
            mystream<<"+("<<SecondP[i]<<")x^"<<l;
        }
    }
    return mystream;
}

istream & operator>>(istream & mystream, Polynom &SecondP)
{
    cout<<"Enter "<< SecondP.DimensionOfPoly() << " coefficients:"<<endl;
    for (int i = 0; i < SecondP.DimensionOfPoly(); i++)
    {
        mystream>>SecondP[i];
    }
    return mystream;
}

Polynom::~Polynom()
{
    n = 0;
    delete [] P;
    P = nullptr;
}
