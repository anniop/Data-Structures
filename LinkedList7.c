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

int Count(PNODE First)
{
    int iCnt = 0;
    while(First != NULL)
    {
        First->data;
        First = First->next;
        iCnt++;
    }
    return iCnt;
}

int main()
{
    
    PNODE Head = NULL;
    int iRet = 0;
    int Arr[20];
    int i =

    printf("Enter The Value You Want to store : \n");
    for(int i = 0;i<=Arr[i];i++)
    {
        scanf("%d",&Arr[i]);
    }
    
    InsertFirst(&Head,Arr[i]);
   

    iRet = Count(Head);
    printf("Number of Elements are %d : \n",iRet);

    return 0;
}