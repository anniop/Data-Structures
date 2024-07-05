#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

void PreOrder(PNODE Root)
{
    if(Root != NULL)
    {
        printf("%d\n",Root->data);
        PreOrder(Root->lchild);
        PreOrder(Root->rchild);
    }
}

void PostOrder(PNODE Root)
{
    if(Root != NULL)
    {
        PostOrder(Root->lchild);
        PostOrder(Root->rchild);
        printf("%d\n",Root->data);
    }
}

bool Search(PNODE Root, int iNo)
{
    bool flag = false;

    if(Root == NULL)
    {
        printf("Tree is Empty\n");
        return false;
    }

    while(Root != NULL)
    {
        if(Root->data == iNo)
        {
            flag = true;
            break;
        }
        else if(iNo > Root->data)
        {
            Root = Root->rchild;
        }
        else if(iNo< Root->data)
        {
            Root = Root->lchild;
        }
    }
    return flag;
}

int CountLeaf(PNODE Root)
{
    static int iCnt = 0;

    if(Root != NULL)
    {
        if((Root->lchild == NULL) && (Root->rchild == NULL))
        {
            iCnt++;
        }
        CountLeaf(Root->lchild);
        CountLeaf(Root->rchild);

    }
    return iCnt;
}


int CountParent (PNODE Root)
{
  static int iCnt = 0;
  if (Root != NULL)
  {
    if (Root -> rchild != NULL && Root -> lchild != NULL)
    {
      iCnt ++;
      CountParent(Root->rchild);
      CountParent(Root->lchild);
    }
  }
  return iCnt;
}

int CountAll(PNODE Root)
{

}

int main()
{

    PNODE Head = NULL;
    bool bRet = false;
    int iRet = 0;

    Insert(&Head,21);
    Insert(&Head,34);
    Insert(&Head,11);
    Insert(&Head,98);
    Insert(&Head,44);
    Insert(&Head,28);
    Insert(&Head,10);
    Insert(&Head,7);
    Insert(&Head,17);

    iRet = CountLeaf(Head);
    printf("Number of Leaf Nodes are : %d\n",iRet);

    iRet = CountParent(Head);
    printf("Number of Parent Nodes are : %d\n",iRet);

    
    return 0;
}