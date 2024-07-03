// Generic Linked List

#include<iostream>
using namespace std;

template<class T>

struct node
{
    T data;
    struct node *next;
};



template<class T>
class SinglyLL
{
    private:
        struct node<T> *First;
        int iCount;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template<class T>
SinglyLL<T>::SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void SinglyLL<T>::Display()
{
    struct node<T>* temp = First;

    while (temp != NULL)
    {
        cout<<"|"<<temp->data<<"| => ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template<class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template<class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct node<T>* newn = new node<T>;

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

template<class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct node<T>* newn = new node<T>;
    struct node<T>* temp = First;

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

template<class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct node<T>* newn = NULL;
    int i = 0;
    struct node<T>* temp = NULL;
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
        
        newn = new node<T>;
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

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    struct node<T>* newn = new node<T>;
    struct node<T>* temp = First;

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

template<class T>
void SinglyLL<T>::DeleteLast()
{
    struct node<T>* newn = new node<T>;
    struct node<T>* temp = First;

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

template<class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct node<T>* temp1 = NULL;
    struct node<T>* temp2 = NULL;
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
    // Linked List of Integer
    
    SinglyLL<int> *iobj = new SinglyLL<int>();
     cout<<"-------------------------------------------------------------------\n";
    cout<<"Linked List of Integer\n";
    cout<<"--------------------------------------------------------------------\n";
    int iRet = 0;

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of Elements are :"<<iRet<<endl;

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of Elements are :"<<iRet<<endl;


    iobj->InsertAtPos(105,5);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of Elements are :"<<iRet<<endl;

    iobj->DeleteAtPos(5);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of Elements are :"<<iRet<<endl;
    cout<<"\n";
    cout<<"-----------------------------------------------------------------\n";

    // Linked List of Character

   
    SinglyLL<char> *cobj = new SinglyLL<char>();

    cout<<"Linked List of Characters\n";
    cout<<"-------------------------------------------------------------------\n";
    cobj->InsertFirst('A');
    cobj->InsertFirst('B');
    cobj->InsertFirst('C');

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of Elements are :"<<iRet<<endl;

    cobj->InsertLast('D');
    cobj->InsertLast('E');
    cobj->InsertLast('F');

    cobj->Display();
    iRet = cobj->Count();
    


    cobj->InsertAtPos('G',5);

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of Elements are :"<<iRet<<endl;

    cobj->DeleteAtPos(5);

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of Elements are :"<<iRet<<endl;
    cout<<"\n";
    cout<<"-------------------------------------------------------------\n";

    // Linked List of Float

    SinglyLL<float> *fobj = new SinglyLL<float>();

    cout<<"Linked List of Float\n";
    cout<<"------------------------------------------------------------\n";

    fobj->InsertFirst(51.32);
    fobj->InsertFirst(21.43);
    fobj->InsertFirst(11.56);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of Elements are :"<<iRet<<endl;

    fobj->InsertLast(101.78);
    fobj->InsertLast(111.14);
    fobj->InsertLast(121.67);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of Elements are :"<<iRet<<endl;


    fobj->InsertAtPos(105.78,5);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of Elements are :"<<iRet<<endl;

    fobj->DeleteAtPos(5);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of Elements are :"<<iRet<<endl;
    cout<<"\n";
    cout<<"--------------------------------------------------------------------\n";

    // Linked List of Double

    SinglyLL<double> *dobj = new SinglyLL<double>();

    cout<<"Linked List of Double\n";
    cout<<"----------------------------------------------------------------------\n";

    dobj->InsertFirst(51.32234);
    dobj->InsertFirst(21.43234);
    dobj->InsertFirst(11.564234);

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of Elements are :"<<iRet<<endl;

    dobj->InsertLast(101.78231);
    dobj->InsertLast(111.14562);
    dobj->InsertLast(121.672341);

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of Elements are :"<<iRet<<endl;


    dobj->InsertAtPos(105.783245,5);

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of Elements are :"<<iRet<<endl;

    dobj->DeleteAtPos(5);

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of Elements are :"<<iRet<<endl;
    cout<<"\n";
    cout<<"-----------------------------------------------------------\n";

    return 0;
}