#include<iostream>
#include"typedef.h"
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;  //$
};

class DoublyLL
{
    private: 
        PNODE First;
        int iCount;
    
    public:
        DoublyLL();
        void Display();
        int Count();
        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo,int iPos);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        
};

DoublyLL::DoublyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

void DoublyLL::Display() 
{
    PNODE temp = First;

    while (temp != NULL) {
        cout << "|" << temp->data << "| => ";
        temp = temp->next;
    }
    cout << endl;
}

int DoublyLL::Count()
{
    return iCount;
}

void DoublyLL::InsertFirst(int iNo)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = First;
    newn->prev = NULL;

    if (First == NULL) 
    {
        First = newn;
    } else 
    {
        First->prev = newn; //$
        First = newn;
    }

    iCount++;
}

void DoublyLL::InsertLast(int iNo)
{

    PNODE newn = new NODE;
    PNODE temp = First;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp ->next = newn;
        newn->prev = temp;  //$
    }
    iCount++;

}

void DoublyLL::InsertAtPos(int iNo,int iPos)
{
    PNODE newn = NULL;
    int i = 0;
    PNODE temp = NULL;

    if((iPos < 0) || (iPos > iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(iNo);
    }
    else
    {
        temp = First;
        newn = new NODE;
        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;  //$
        
        for(i = 1;i < iPos-1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next; 
        temp->next->prev = newn;    //$
        temp->next = newn;
        newn->prev = temp;  //$

        iCount++;
    }
}

void DoublyLL::DeleteFirst()
{
    PNODE newn = new NODE;
    PNODE temp = First;

    if(First == NULL)
    {
        cout<<"Unable to perform the operation\n";
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete temp;
        First->prev = NULL;    //$
    }
    iCount--;
}

void DoublyLL::DeleteLast()
{
    PNODE newn = new NODE;
    PNODE temp = First;

    if(First == NULL)
    {
        cout<<"Unable to perform the operation\n";
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

void DoublyLL::DeleteAtPos(int iPos)
{
    int i = 0;
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->prev = temp1;    //$
        delete temp2;
        iCount--;
    }
}

int main()
{
    
    int iRet = 0;

    DoublyLL obj;

    obj.InsertFirst(11);
    obj.InsertFirst(21);
    obj.InsertFirst(51);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of Nodes are : "<<iRet<<endl;

    obj.InsertLast(101);
    obj.InsertLast(121);
    obj.InsertLast(151);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of Nodes are : "<<iRet<<endl;

    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of Nodes are : "<<iRet<<endl;

    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of Nodes are : "<<iRet<<endl;

    obj.InsertAtPos(200,4);
   
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of Nodes are : "<<iRet<<endl;

    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of Nodes are : "<<iRet<<endl;


    return 0;
}