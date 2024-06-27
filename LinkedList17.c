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

void InsertLast(PPNODE First, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;     //$


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
       newn->prev = temp;      //$
    }
    
}  

void InsertAtPost(PPNODE First, int iNo, int iPos)
{
    int iLength = 0;
    int i = 0;  
    iLength = Count(*First);
    PNODE newn = NULL;
    PNODE temp = NULL;
    

    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid Position\n");
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(First,iNo);
    }
    else if (iPos == iLength+1)
    {
        InsertLast(First,iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;  //$
        temp = *First;

        for(i = 1;i < iPos;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;    //$
        temp->next = newn;
        newn->prev = temp;      //$

    }
}

void DeleteFirst(PPNODE First)
{
    if(*First == NULL)
    {
        printf("Unable to delete the node LL is empty\n");
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        *First = (*First) ->next;
        free((*First) ->prev);  //$
        (*First)->prev = NULL;   //$
    }
}

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

    InsertLast(&Head,23);
    InsertLast(&Head,33);
    InsertLast(&Head,43);


    Display(Head);
    iRet = Count(Head);
    printf("Number of Nodes are : %d\n",iRet);

    InsertAtPost(&Head,105,5);


    Display(Head);
    iRet = Count(Head);
    printf("Number of Nodes are : %d\n",iRet);

    DeleteFirst(&Head);

     Display(Head);
    iRet = Count(Head);
    printf("Number of Nodes are : %d\n",iRet);
    


    return 0;
}