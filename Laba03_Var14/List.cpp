#include "List.h"
#include <iostream>
#include <string>
using namespace std;

void	List::InsertHead(const int& val)
{
    if (head == 0)
    {
        ListItem *ptr = new ListItem;
        ptr->info = val;
        head = ptr;
        tail = head;
        tail->next = head;
        return;
    }
    ListItem *ptr = new ListItem;
    ptr->info = val;
    tail->next = ptr;
    ptr->next = head;
    head = ptr;
}
int		List::GetHead() const
{
    if (IsEmpty()) throw Excpt("can't show the head : the list is empty!!!");
    return head->info;
}
int		List::Size() const
{
    if (IsEmpty()) return 0;
    ListItem *ptr = head;
    int count = 1;
    while (ptr->next != head)
    {
        ++count;
        ptr = ptr->next;
    }
    return count;
}
void	List::Print() const
{
    if (IsEmpty()) throw Excpt("Can't print the list : it's empty!!!");
    ListItem *ptr = head;
    do
    {
        cout<<ptr->info<<"\t";
        ptr = ptr->next;
    }
    while (ptr != head);
}
void	List::MoveHead(const int pos_num)
{
    if (IsEmpty()) throw Excpt("can't move the head : the list is empty!!!");
    if (pos_num < 0) throw Excpt("can't move the head : the index is negative!!!");
    ListItem *ptr1 = head;
    for (int i=0; i<pos_num; i++)
    {
        ptr1 = ptr1->next;
        head = ptr1;
        tail = tail->next;
    }
}
void	List::DeleteHead()
{
    if (IsEmpty()) throw Excpt("can't delete the element : the list is empty!!!");
    if (Size()==1)
    {
        delete head;
        head = NULL;
        tail = head;
        return;
    }
    ListItem *ptr = head, *ptr1 = head->next;
    head = NULL;
    delete ptr;
    head = ptr1;
    tail->next = head;

}
bool	List::IsEmpty() const
{
    if (head == NULL)
        return true;
    return false;
}
void	List::ListCross(const List& lst)
{
    if (lst.IsEmpty() || IsEmpty())
    {
        Erase();
        return;
    }
    List LCross(lst);
    bool found;
    ListItem *ptr = head, *ptr1 = LCross.head;
    int size = LCross.Size();
    for (int i=0; i<size; i++)
    {
        found = false;
        ptr = head;
        do
        {
            if (ptr->info == ptr1->info)
            {
                found = true;
                break;
            }
            ptr = ptr->next;
        }
        while (ptr != head);
        if (!found)
        {
            LCross.DeleteHead();
            ptr1 = LCross.head;
        }
        else
        {
            ptr1 = ptr1->next;
            LCross.MoveHead(1);
        }
    }
    Erase();
    ptr1 = LCross.head;
    if (LCross.IsEmpty()) return;
    do
    {
        InsertHead(ptr1->info);
        ptr1 = ptr1->next;
    }
    while(ptr1 != LCross.head);
}
void	List::ListUnion(List& lst)
{
    if (lst.IsEmpty()) return;
    if (IsEmpty())
    {
        ListItem *ptr = lst.head;
        do
        {
            InsertHead(ptr->info);
            ptr = ptr->next;
        }
        while(ptr != lst.tail);
        MoveHead(lst.Size()-1);
        return;
    }
    bool matches = false;
    int size = Size();
    ListItem  *ptr = head, *ptr1 = lst.head;
    for (int i=0; i<size; i++)
    {
        do
        {
            if (ptr->info == ptr1->info)
            {
                matches = true;
                break;
            }
            ptr1 = ptr1->next;
        }
        while (ptr1 != lst.head);
        if (!matches)
            InsertHead(ptr1->info);
        else
            matches = false;
        ptr = ptr->next;
    }
}
void	List::ListSubstract(List& lst)
{
    if (lst.IsEmpty()) return;
    if (IsEmpty()) throw Excpt("invalid operation ""substract"" : initial list is empty!!!");

    bool matches = false;
    int size = Size();
    ListItem  *ptr = head, *ptr1 = lst.head;
    for (int i=0; i<size; i++)
    {
        do
        {
            if (ptr->info == ptr1->info)
            {
                DeleteHead();
                matches = true;
                break;
            }
            ptr1 = ptr1->next;
        }
        while (ptr1 != lst.head);
        if (!matches)
            ptr = ptr->next;
        MoveHead(1);
        matches = false;
    }
    MoveHead(Size()-1);
}
void	List::DeleteMatching()
{
    if (IsEmpty()) throw Excpt("can't delete matching: the list is empty");
    ListItem *ptr = head->next;
    int val = head->info;
    bool del = false;
    for (int i=1; i<Size(); i++)
    {
        for (int j=i; j<Size(); j++)
        {
            if (ptr->info == val)
            {
                DeleteHead();
                del = true;
                break;
            }
            ptr = ptr->next;
        }
        if (!del)
            MoveHead(1);
        ptr = head->next;
        val = head->info;
        del = false;
    }
}
void	List::Erase()
{
    while (head)
    {
        if (Size()==1)
        {
            DeleteHead();
            head = NULL;
            tail = head;
            return;
        }
        DeleteHead();
    }
}
List::List()
{
    head = NULL;
    tail = head;
}
List::List(const int vals[],int size)
{
    for (int i=0; i<size; i++)
    {
        InsertHead(vals[i]);
        MoveHead(1);
    }
}
List::List(const List& lst)
{
    if (lst.IsEmpty()) throw Excpt("nothing to copy, the list is empty!!!");
    Erase();
    ListItem *ptr = lst.head;
    do
    {
        InsertHead(ptr->info);
        MoveHead(1);
        ptr = ptr->next;
    }
    while (ptr != lst.head);

}
List&	List::operator= (const List& lst)
{
    if (this == &lst) return *this;
    Erase();
    ListItem *ptr = lst.head;
    do
    {
        InsertHead(ptr->info);
        MoveHead(1);
        ptr = ptr->next;
    }
    while (ptr != lst.head);
    return *this;
}
List::~List()
{
    Erase();
}
