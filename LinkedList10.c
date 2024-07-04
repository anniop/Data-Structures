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

//void Display(PNODE First)
//{
//    while (First != NULL)
//    {
//        printf("| %d |->",First->data);
//        First = First->next;
//    }
//    printf("| NULL |");
//    
//} 

void Display(PNODE First)
{
    if(First != NULL)
    {
        printf("%d\t",First->data);
        Display(First->next);
    }
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

int main()
{
    
    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head,51);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);

    InsertLast(&Head,101);
    InsertLast(&Head,111);
    InsertLast(&Head,121);

    Display(Head);

    iRet = Count(Head);
    printf("\n");
    printf("Number of Nodes are : %d\n",iRet);

    printf("\n");
    printf("Deleting First Node\n");

    DeleteFirst(&Head);

    Display(Head);

    iRet = Count(Head);
    printf("\n");
    printf("Number of Nodes are : %d\n",iRet);

    printf("Deleteing Last Node\n");

    printf("\n");
    DeleteLast(&Head);

    Display(Head);

    iRet = Count(Head);
    printf("\n");
    printf("Number of Nodes are : %d\n",iRet);

    return 0;
}

