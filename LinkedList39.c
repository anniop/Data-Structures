#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE First, PPNODE Last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL) )
    {
        *First = newn;  
        *Last = newn;   
    }
    else
    {
        newn->next = *First;
        *First = newn;
    }
    (*Last)->next = *First;
}

void InsertLast(PPNODE First, PPNODE Last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL) )
    {
        *First = newn;  
        *Last = newn;   
    }
    else
    {
        (*Last)->next = newn;
        *Last = newn;
    }
    (*Last)->next = *First;
}

void DeleteFirst(PPNODE First, PPNODE Last)
{

    if((*First == NULL) && (*Last == NULL) )    // Empty Linked List
    {
        return; 
    }
    else if(*First == *Last)    // Single Node
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else    // Multiple Nodes
    {
        *First = (*First)->next;
        free((*Last)->next);
        (*Last)-> next = *First;
    }
   
}

void DeleteLast(PPNODE First, PPNODE Last)
{
    if((*First == NULL) && (*Last == NULL) )
    {
        return; 
    }
    else if(*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        PNODE temp = *First;

        while(temp->next != *Last)
        {
            temp = temp->next;
        }
        free(*Last);
        *Last = temp;
        (*Last)->next = *First;
    }
        
}

void Display(PNODE First, PNODE Last)
{
   
    if((First == NULL) && (Last == NULL))
    {
        printf("Linked List is empty\n");
        return;
    }

    do {
        printf(" | %d | ->", First->data);
        First = First->next;
    } while (First != Last->next);
    printf("\n");
}



int Count(PNODE First, PNODE Last)
{

    if((First == NULL) && (Last == NULL))
    {
       printf("Linked List is Empty\n");
    }

    int iCnt = 0;
    do
    {
        iCnt++;
        First = First->next;
    } while (First != Last->next);
    return iCnt;
}

void InsertAtPost(PPNODE First, PPNODE Last,int iNo, int iPos)
{
    int i = 0;
    int iLength = 0;
    PNODE newn = NULL;
    PNODE temp = *First;

    iLength = Count(*First,*Last);
    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid Position\n");
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(First,Last,iNo);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(First,Last,iNo);
    }
    else
    {
        
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = iNo;
        newn->next = NULL;

        for(i = 1;i<iPos-1;i++)
        {
          temp = temp->next;  
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPost(PPNODE First, PPNODE Last, int iPos)
{
    int i = 0;
    int iLength = 0;
    PNODE newn = NULL;
    PNODE temp1 = *First;
    PNODE temp2 = NULL;

    iLength = Count(*First,*Last);
    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid Position\n");
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst(First,Last);
    }
    else if(iPos == iLength+1)
    {
        DeleteLast(First,Last);
    }
    else
    {
        
        temp1 = *First;
        for(i = 1;i<iPos-1;i++)
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
    PNODE Tail = NULL;  
    int iRet = 0;

    InsertFirst(&Head,&Tail,51);
    InsertFirst(&Head,&Tail,21);
    InsertFirst(&Head,&Tail,11);

    InsertLast(&Head,&Tail,101);
    InsertLast(&Head,&Tail,111);
    InsertLast(&Head,&Tail,121);
    
    Display(Head,Tail);
    iRet  = Count(Head, Tail);
    printf("Number of Nodes are : %d\n", iRet);
    
    DeleteFirst(&Head,&Tail);

    Display(Head,Tail);
    iRet  = Count(Head, Tail);
    printf("Number of Nodes are : %d\n", iRet);

    DeleteLast(&Head,&Tail);

    Display(Head,Tail);
    iRet  = Count(Head, Tail);
    printf("Number of Nodes are : %d\n", iRet);

    DeleteAtPost(&Head,&Tail,5);

    Display(Head,Tail);
    iRet  = Count(Head, Tail);
    printf("Number of Nodes are : %d\n", iRet);

   

    return 0;
}