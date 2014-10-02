#ifndef CLASS_POLYNOM_H_INCLUDED
#define CLASS_POLYNOM_H_INCLUDED
#include <iostream>

class Polynom
{
      int *P;
      int n;
   public:
     Polynom() : P(nullptr), n(0) {};

     Polynom(int n);

     Polynom(Polynom & SecondP);

     Polynom operator*(int x);

     Polynom operator+(Polynom & SecondP) ;

     Polynom operator-(Polynom & SecondP) ;

     Polynom & operator=(Polynom & SecondP);

     int & operator[](int i)  {return P[i];}

     ~Polynom();

     int DimensionOfPoly() {return n;}

     void FindQuantityOfPolynom(int x);

     friend std::ostream & operator<<(std::ostream & mystream, Polynom &SecondP);
     friend std::istream & operator>>(std::istream & mystream, Polynom &SecondP);
};

#endif // CLASS_POLYNOM_H_INCLUDED

