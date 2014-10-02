#include <iostream>
#include<conio.h>

using namespace std;

void InsertSort(int *mas, int n) // функция, осуществляющая сортировку вставками
{
    int key=0, temp=0;
    for (int i=0; i<n-1; i++)
    {
        key=i+1;
        temp=mas[key];
        for (int j=i+1; j>0; j--)
        {
            if (temp<mas[j-1])
            {
                mas[j]=mas[j-1];
                key=j-1;
            }
        }
        mas[key]=temp;
    }
    cout<<endl<<"Результирующий массив: ";
    for (int i=0; i<n; i++)
        cout<<mas[i]<<" ";
}


int main ()
{
    setlocale(LC_ALL, "Rus");
    int n;
    cout<<"Количество элементов в массиве > ";
    cin>>n;
    int *mas=new int[n];
    for (int i=0; i<n; i++)
    {
        cout<<i+1<<" элемент > ";
        cin>>mas[i];
    }
    InsertSort(mas, n);
    delete[] mas;
    getch();
    return 0;
}
