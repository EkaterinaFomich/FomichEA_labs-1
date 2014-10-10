#include "List.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(0));

    int  list_size = 10, right = 10, left = -10;
    List lst1,lst2;
    //генерируем случайную последовательность с помощью пересечения двух посл-тей
    try
    {
        for (int i=0; i<list_size; i++)
        {
            lst1.InsertHead(rand()%(right-left+1)+left);
            lst2.InsertHead(rand()%(right-left+1)+left);
        }
        lst2.Print();
        cout<<endl;
        lst1.ListCross(lst2); // пересечение может быть пустое,в этом случае выбросит исключение
        lst1.Print();
        cout<<endl;
        lst1.DeleteMatching();
        cout<<"random sequence:\t";
        lst1.Print();
        cout<<endl;
    }

    catch(List::Excpt &obj)
    {
        cout<<obj.msg<<endl;
    }
    return 0;
}
