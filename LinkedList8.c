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
    
}

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
    
}

void Display(PNODE First)
{
    while(First != NULL)
    {
        printf("| %d |->",First->data);
        First = First->next;
    }
    printf("| NULL |\t");
}

int main()
{
    
    PNODE Head = NULL;
    
 ///////////////////////////////////////   

    InsertFirst(&Head,51);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);

///////////////////////////////////////

    InsertLast(&Head,111);
    InsertLast(&Head,121);
    InsertLast(&Head,151);

//////////////////////////////////////

    Display(Head);


    return 0;
}