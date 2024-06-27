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

}

int SinglyLL::Count()
{
    return iCount;
}

void SinglyLL::InsertFirst(int iNo)
{

}

void SinglyLL::InsertLast(int iNo)
{

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
    iRet = obj.Count();

    cout<<"Number of Elements are : "<<iRet<<endl;
    

    return 0;
}