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
    while (First != NULL)
    {
        printf("| %d |->",First->data);
        First = First->next;
    }
    printf("| NULL |");
    
} 

int Count(PNODE First)
{
    int iCnt = 0;
    while (First != NULL)
    {
        iCnt++;
        First = First->next;
    }
    return iCnt;
} 

void DeleteFirst(PPNODE First)
{

    PNODE temp = NULL;

    if(*First == NULL) // Case 1 :- Linked List is Empty.
    {
        printf("Unable to delete as linked list is empty\n");
        return;
    }
    else if((*First) -> next == NULL) // Case 2 :- Linked List Contaions one Node.
    {
        free(*First);
        *First = NULL;
    }
    else // Case 3 :- Linked List Contains more than one node.
    {
        temp = *First;
        *First = (*First) ->next;
        free(temp); 
    }
}

void DeleteLast(PPNODE First)
{
    PNODE temp = NULL;
    if(*First == NULL) // Case 1
    {
        printf("Unable to delete as linked list is empty\n");
        return;
    }
    else if((*First) -> next == NULL) // Case 2
    {
        free(*First);
        *First = NULL;
    }
    else // Case 3
    {
        temp = *First;
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPos(PPNODE First ,int iNo, int iPos)
{
    int iLength = 0;
    iLength = Count(*First);
    PNODE newn = NULL;
    PNODE temp = NULL;
    int i = 0;
 
    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid Position");
        return;
    }
    if(iPos == 1) 
    {
        InsertFirst(First,iNo);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(First,iNo);
    }
    else
    {
        newn =(PNODE)malloc(sizeof(NODE));

        newn->data = iNo;
        newn->next = NULL;
        temp = *First;
        for(i = 1; i<iPos-1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

    }
}

void DeleteAtPos(PPNODE First , int iPos)
{
    int iLength = 0;
    int i = 0;
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;
    iLength = Count(*First);

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid Position");
        return;
    }
    if(iPos == 1) 
    {
        DeleteFirst(First);
    }
    else if(iPos == iLength)
    {
        DeleteLast(First);
    }
    else
    {
        temp1 = *First;
        for(i = 1;i < iPos-1;i++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);

    }
}


int main()
{
    
    PNODE Head = NULL;
    int iRet = 0;

    
    InsertFirst(&Head,91);
    InsertFirst(&Head,51);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);

    InsertLast(&Head,101);
    InsertLast(&Head,111);
    InsertLast(&Head,121);

    InsertAtPos(&Head,105,5);

    Display(Head);

    iRet = Count(Head);
    printf("\n");
    printf("Number of Nodes are : %d\n",iRet);

    DeleteAtPos(&Head,5);

    Display(Head);

    iRet = Count(Head);
    printf("\n");
    printf("Number of Nodes are : %d\n",iRet);


    return 0;
}

