#ifndef CLASS_LIST_H_INCLUDED
#define CLASS_LIST_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>

class List
{
private:
    struct ListItem
    {
        int info;
        ListItem *next;
    };
    ListItem *head;
    ListItem *tail;
public:
    class Excpt
    {
    public:
        string msg;
        Excpt(string msgg)
        {
            msg = msgg;
        }
    };
    void InsertHead(const int& val);
    int	GetHead() const;
    int	Size() const;
    void Print() const;
    void MoveHead(const int pos_num);
    void DeleteHead();
    bool IsEmpty() const;
    void ListCross(const List& lst);
    void ListUnion(List& lst);
    void ListSubstract(List& lst);
    void DeleteMatching();
    void Erase();
    List();
    List(const int vals[],int size);
    List(const List& lst);
    List& operator=(const List& lst);
    ~List();
};

#endif // CLASS_LIST_H_INCLUDED
