#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE First, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        *First = newn;
    }
}   

void Display(PNODE First)
{
    while(First != NULL)
    {
        printf("| %d |->",First->data);
        First = First -> next;
    }
    printf("NULL\n");
} 

int Count(PNODE First)
{
    int iCnt = 0;

    while(First != NULL)
    {
        iCnt++;
        First = First -> next;
    }
    return iCnt;
} 

int Addition(PNODE First)
{
    int iSum = 0;

    while(First != NULL)
    {
        iSum = iSum + (First->data);
        First = First->next;
    }
    return iSum;
}

int EvenCount(PNODE First)
{
    int iCount = 0;

    while(First != NULL)
    {
        if((First->data)%2==0)
        {
            iCount++;
        }
        First = First->next;
    }
    return iCount;
}

int OddCount(PNODE First)
{
    int iCount = 0;

    while(First != NULL)
    {
        if((First->data)%2!=0)
        {
            iCount++;
        }
        First = First->next;
    }
    return iCount;
}

int FrequencyCount(PNODE First,int No)
{
    int iCount = 0;

    while(First != NULL)
    {
        if((First->data) == No)
        {
            iCount++;
        }
        First = First->next;
    }
    return iCount;
}

bool ReturnSearch(PNODE First, int No)
{
    bool bFlag = false;

    while(First != NULL)
    {
        if((First->data) == No)
        {
            bFlag = true;
            break;
        }
        First = First->next;
    }
    return bFlag;
}

int SearchFirstOccurence(PNODE First, int No)
{
    int iCnt = 1;
    int iPos = -1;

    while(First != NULL)
    {
        if((First->data) == No)
        {   
            iPos = iCnt;
            break;
        }
        iCnt++;
        First = First->next;
    }

    return iPos;
}

int SearchLastOccurence(PNODE First, int No)
{
    int iCnt = 1;
    int iPos = -1;

    while(First != NULL)
    {
        if((First->data) == No)
        {   
            iPos = iCnt;
        }
        iCnt++;
        First = First->next;
    }

    return iPos;
}

int main()
{
    PNODE Head = NULL;
    int iRet = 0;
    bool bRet = false;
    int iNo = 0;

    InsertFirst(&Head,42);
    InsertFirst(&Head,10);
    InsertFirst(&Head,5);
    InsertFirst(&Head,21);
    InsertFirst(&Head,10);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);
    
    Display(Head);

    printf("Enter Number : \n");
    scanf("%d",&iNo);

    iRet = Count(Head);
    printf("Number of Nodes are %d\n",iRet);

    iRet = Addition(Head);

    printf("Addition of Nodes is : %d\n",iRet);

    iRet = EvenCount(Head);

    printf("The Even Numbers in the Linked List is : %d\n",iRet);

    iRet = OddCount(Head);
    printf("The Odd Numbers in the Linked List are : %d\n",iRet);
    
    iRet = FrequencyCount(Head,iNo);
    printf("The Frequency of that number is : %d\n",iRet);

    bRet = ReturnSearch(Head,iNo);
    if(bRet == true)
    {
        printf("The Element is present in the Linked List\n");
    }
    else
    {
        printf("The Elemenet is not present\n");
    }

    iRet = SearchFirstOccurence(Head,iNo);
    printf("The First Occurence of the number is : %d\n",iRet);

    iRet = SearchLastOccurence(Head,iNo);
    printf("The Last Occurence of the number is : %d\n",iRet);
    
    return 0;
}
