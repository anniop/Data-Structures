#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Insert(PPNODE Root, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*Root == NULL)   // Tree is Empty
    {
        *Root = newn;
    }
    else    // Tree Contains atleast one node
    {   
        temp = *Root;

        while(1)
        {
            if(temp->data == iNo)
            {
                printf("Unable to insert element as element is already present\n");
                free(newn);
                break;
            }
            else if(iNo > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
               temp = temp->rchild;
                
            }
            else if(iNo < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
                    
            }
        }
    }

}

void InOrder(PNODE Root)
{
    if(Root != NULL)
    {
        InOrder(Root->lchild);
        printf("%d\n",Root->data);
        InOrder(Root->rchild);
    }
}

int main()
{

    PNODE Head = NULL;

    Insert(&Head,21);
    Insert(&Head,11);
    Insert(&Head,51);

    InOrder(Head);


    return 0;
}