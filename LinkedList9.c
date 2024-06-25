#include<stdio.h>
#include<stdlib.h>
#include"typedef.h"

struct node
{
    int data;
    struct node *next;
};



void InsertLast(PPNODE First, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
       temp = *First;
       while(temp -> next != NULL )
       {
            temp = temp -> next;
       }
       temp -> next = newn;
    }
    
}   // Time Complexity : O(1)

void InsertFirst(PPNODE First, int iNo)
{
    PNODE newn = NULL;
    
    
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn -> next = *First;
        *First = newn;
    }
    
} // Time Complexity : O(N) N is Number of elements of nodes in the Linked List.


void Display(PNODE First)
{
    while (First != NULL)
    {
        printf("| %d |->",First->data);
        First = First->next;
    }
    printf("| NULL |");
    
} // Time Complexity : O(N) N is Number of elements of nodes in the Linked List.

int Count(PNODE First)
{
    int iCnt = 0;
    while (First != NULL)
    {
        iCnt++;
        First = First->next;
    }
    return iCnt;
} // Time Complexity : O(N) N is Number of elements of nodes in the Linked List.

int main()
{
    
    PNODE Head = NULL;

    InsertFirst(&Head,51);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);

    InsertLast(&Head,101);
    InsertLast(&Head,111);
    InsertLast(&Head,121);

    Display(Head);

    int iRet = Count(Head);
    printf("\n");
    printf("Number of Nodes are : %d\n",iRet);

    return 0;
}

/*

Step 1:- Allocate Memory for the node
Step 2:- Initialise the node
Step 3:- Check Whether the Linked List is empty or not
Step 4:- If Linked List is empty store the address of new node in the heap pointer through First
Step 5:- OtherWise store the Address of old first node in the next of new node
Step 6:- Update the Head Accordingly


*/