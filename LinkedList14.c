// Doubly Linear Linked List
// "$"" indicates the number of lines added newly than singly linear linked list.

#include<stdio.h>
#include<stdlib.h>
#include"typedef.h"

struct node
{
    int data;
    struct node *next;
    struct node *prev;  //$
};


int Count(PNODE First)
{
    int iCnt = 0;
    while(First != NULL)
    {
        
        First = First->next;
        iCnt++;
    }
    return iCnt;
}

 

void InsertFirst(PPNODE First, int iNo)
{
    PNODE newn = NULL;
    
    
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;   //$

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn -> next = *First;
        (*First)->prev = newn;  //$
        *First = newn;
    }
    
} 



void Display(PNODE First)
{
    printf("\nNULL");
    while (First != NULL)
    {
        printf("| %d |<=>",First->data);
        First = First->next;
    }
    printf("NULL\n");
    
}




int main()
{

    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head,8);
    InsertFirst(&Head,4);
    InsertFirst(&Head,12);

    Display(Head);
    iRet = Count(Head);
    printf("Number of Nodes are : %d\n",iRet);
    


    return 0;
}