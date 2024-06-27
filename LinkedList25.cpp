#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class SinglyLL
{
    public:
        PNODE First;
        int iCount;
        
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo,int iPos);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

SinglyLL::SinglyLL()
{
    cout<<"Inside Constructor"<<endl;
    First = NULL;
    iCount = 0;
}

void SinglyLL::Display()
{
    while(First != NULL)
    {
        cout<<"| "<<First->data<<" |"<<"->";
        First = First->next;
    }
    cout<<"| NULL |\n";
}

int SinglyLL::Count()
{
    return iCount;
}

void SinglyLL::InsertFirst(int No)
{
    PNODE newn = new NODE;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

void SinglyLL::InsertLast(int iNo)
{
    PNODE newn = NULL;
    PNODE temp = First;

    newn  = new NODE;   // Mallocs

    newn->data = iNo;
    newn->next = NULL;

    if(First == NULL)   // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next; 
        }
        temp->next = newn;
    }
    iCount++;
}

void SinglyLL::InsertAtPos(int iNo,int iPos)
{

}

void SinglyLL::DeleteFirst()
{

}

void SinglyLL::DeleteLast()
{

}

void SinglyLL::DeleteAtPos(int iPos)
{

}

int main()
{
    
    SinglyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Elements are : "<<iRet<<endl;
    
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Elements are : "<<iRet<<endl;

    return 0;
}