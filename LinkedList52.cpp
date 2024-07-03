// Linked List of Float
#include<iostream>
using namespace std;

struct node
{
    float data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;


class SinglyLL
{
    private:
        PNODE First;
        int iCount;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(float No);
        void InsertLast(float No);
        void InsertAtPos(float No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

SinglyLL::SinglyLL()
{
    cout<<"Inside the Constructor\n";
    First = NULL;
    iCount = 0;
}

void SinglyLL::Display()
{
    PNODE temp = First;

    while (temp != NULL)
    {
        cout<<"|"<<temp->data<<"| => ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

int SinglyLL::Count()
{
    return iCount;
}

void SinglyLL::InsertFirst(float No)
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

void SinglyLL::InsertLast(float No)
{
    PNODE newn = new NODE;
    PNODE temp = First;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp -> next = newn;
    }
    iCount++;
}

void SinglyLL::InsertAtPos(float No, int iPos)
{
    PNODE newn = NULL;
    int i = 0;
    PNODE temp = NULL;
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;
        
        newn = new NODE;
        newn->data = No;
        newn->next = NULL;
        for(i = 1;i<iPos-1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;

    }
}

void SinglyLL::DeleteFirst()
{
    PNODE newn = new NODE;
    PNODE temp = First;

    if (First == NULL)
    {
        cout<<"Unable to Perform the Operation\n"<<endl;
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;  
}

void SinglyLL::DeleteLast()
{
    PNODE newn = new NODE;
    PNODE temp = First;

    if (First == NULL)
    {
        cout<<"Unable to Perform the Operation\n"<<endl;
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp ->next;
        temp->next = NULL;
    }
    iCount--; 
}

void SinglyLL::DeleteAtPos(int iPos)
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
        
        for(i = 1;i<iPos-1;i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        iCount--;
    }
}

int main()
{
    SinglyLL obj;

    float iRet = 0.0f;

    obj.InsertFirst(51.43f);
    obj.InsertFirst(21.67f);
    obj.InsertFirst(11.34f);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Elements are :"<<iRet<<endl;

    obj.InsertLast(101.90f);
    obj.InsertLast(111.40f);
    obj.InsertLast(121.43f);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Elements are :"<<iRet<<endl;


    obj.InsertAtPos(105.43f,5);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Elements are :"<<iRet<<endl;

    obj.DeleteAtPos(5);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of Elements are :"<<iRet<<endl;


    return 0;
}