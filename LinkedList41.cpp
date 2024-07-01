#include <iostream>
using namespace std;

struct node {
  int data;
  struct node * prev;
  struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyCLL {
  private:
    PNODE First;
    PNODE Last;
    int iCount;

  public:
    DoublyCLL();

    void Display();
    int Count();

    void InsertFirst(int No);
    void InsertLast(int No);
    void InsertAtPos(int No, int Pos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int Pos);

};

DoublyCLL::DoublyCLL(){
  First = NULL;
  Last = NULL;
  iCount = 0;
}

void DoublyCLL::Display(){
  if(First == NULL && Last == NULL)
  {
      cout<<"Linked List is Empty\n";
      return;
  }
  else
  {
    do
    {
    cout<<"| "<< First->data<<"->";
    First = First ->next;
    }while(Last->next != First);
  }
}
int DoublyCLL::Count(){
  return iCount;
}

void DoublyCLL::InsertFirst(int No){
  PNODE newn = NULL;
  newn = new NODE;
  newn -> data = No;
  newn -> next = NULL;
  newn -> prev = NULL;

  if (First == NULL && Last == NULL){
    First = newn;
    Last = newn;
  }
  else{
    newn -> next = First;
    First -> prev = newn;
    First = newn;
  }
  First -> prev = Last;
  Last -> next = First;
  iCount ++;
}
void DoublyCLL::InsertLast(int No){
  PNODE newn = NULL;
  newn = new NODE;

  newn -> data = No;
  newn -> next = NULL;
  newn -> prev = NULL;

  if (First == NULL && Last == NULL){
    First = newn;
    Last = newn;
  }
  else{
    newn -> prev = Last;
    Last -> next = newn;
    Last = newn;
  }
  Last -> next = First;
  First -> prev = Last;

  iCount ++;
}
void DoublyCLL::InsertAtPos(int No, int Pos){

  if (Pos < 1 || Pos > (iCount + 1)){
    cout<<"Invalid Position"<<endl;
    return;
  }

  if (Pos == 1){
    InsertFirst(No);
  }
  else if (Pos == (iCount+1)){
    InsertLast(No);
  }
  else{
    PNODE newn = NULL;
    newn = new NODE;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    int i = 0;
    PNODE temp = First;
    for (i = 1; i < (Pos - 1); i++){
      temp = temp -> next;
    }

    newn -> next = temp -> next;
    temp -> next -> prev = newn;
    temp -> next = newn;
    newn -> prev = temp;

    iCount++;
  }
}

void DoublyCLL::DeleteFirst()
{
	if(First == NULL && Last == NULL)	// Empty LL
	{
		return;
	}
	else if (First == Last)		// Single node in LL
	{
		delete First;
		First = NULL;
		Last = NULL;
	}
	else	// Multiple Nodes in LL
	{

	}
	iCount--;
  

}
void DoublyCLL::DeleteLast()
{
	if(First == NULL && Last == NULL)	// Empty LL
	{
		return;
	}
	else if (First == Last)		// Single node in LL
	{
		delete First;
		First = NULL;
		Last = NULL;
	}
	else	// Multiple Nodes in LL
	{

	}
	iCount--;
}

void DoublyCLL::DeleteAtPos(int Pos)
{

  
}

int main (){
  int iRet = 0;
  DoublyCLL obj;
  //InsertFirst
  obj.InsertFirst(51);
  obj.InsertFirst(21);
  obj.InsertFirst(11);
  obj.Display();
  iRet = obj.Count();
  cout<<"Total Nodes: "<<iRet<<endl;

  // InsertLast
  obj.InsertLast(101);
  obj.InsertLast(111);
  obj.InsertLast(121);
  obj.Display();
  iRet = obj.Count ();
  cout<<"Total Nodes: "<<iRet<<endl;

  // DeleteFirst(&First,&Last);
  obj.DeleteFirst();
  obj.Display();
  iRet = obj.Count();
  cout<<"Total Nodes: "<<iRet<<endl;

  // Delete Last
  obj.DeleteLast();
  obj.Display();
  iRet = obj.Count();
  cout<<"Total Nodes: "<<iRet<<endl;
  //
  obj.InsertAtPos(71,3);
  obj.Display();
  iRet = obj.Count();
  cout<<"Total Nodes: "<<iRet<<endl;

  obj.DeleteAtPos(3);
  obj.Display();
  iRet = obj.Count();
  cout<<"Total Nodes: "<<iRet<<endl;

  return 0;
}
