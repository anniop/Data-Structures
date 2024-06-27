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

void DeleteLast(PPNODE First)
{
    PNODE temp = NULL;
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
        temp = *First;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void DeleteatPos(PPNODE First , int iPos)
{
    int iLength = 0;
    int i = 0;  
    iLength = Count(*First);
    PNODE temp = NULL;
    

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid Position\n");
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst(First);
    }
    else if (iPos == iLength)
    {
        DeleteLast(First);
    }
    else
    {
       
        temp = *First;

        for(i = 1;i < iPos;i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);     //$
        temp->next->prev = temp;    //$

    }
}