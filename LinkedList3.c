#include<stdio.h>
#include<stdlib.h>

struct node
{
    int Data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

int main()
{

    PNODE Head = NULL;
    NODE obj1;
    NODE obj2;
    NODE obj3;

    obj1.Data = 11;
    obj1.next = &obj2;

    obj2.Data = 21;
    obj2.next = &obj3;

    obj3.Data = 51;
    obj3.next = NULL;

    printf("Head : %d\n", Head);
    printf("&obj1 : %d\n",&obj1);
    printf("&obj2 : %d\n",&obj2);
    printf("&obj3 : %d\n",&obj3);

    printf("Head->Data : %d\n",Head->Data);
    printf("Head->Next : %d\n",Head->next);
    printf("Head->Next->Data : %d\n",Head->next->next);
    printf("Head->Next->Next->Next : %d\n",Head->next->next->next);
    printf("Head->Next->Data : %d\n",Head->next->Data);
    printf("Head->Next->Next->Data : %d\n",Head->next->next->Data);


    return 0;
}