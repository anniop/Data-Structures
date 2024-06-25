#include<stdio.h>
#include<stdlib.h>
#include"typedef.h"

struct node 
{
    int data;
    struct node *next;
};

void InsertFirst(PPNODE First, int iNo)
{
    PNODE newn = NULL;
    
    //Step 1:- Allocate Dynamic Memory for New Node
    newn = (PNODE)malloc(sizeof(NODE));

    // Step 2 :- Initialize the new Node
    newn->data = iNo;
    newn->next = NULL;

    // Step 3 :- Check if the linked list is empty
    if(*First == NULL)
    {
        *First = newn;
    }
   //If Linked List contains atleast one node in it
    else
    {
        newn -> next = *First;
        *First = newn;
    }
    
}


int main()
{
    
    PNODE Head = NULL;
    
    InsertFirst(&Head,51);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);


    return 0;
}