class node
{
    public int data;
    public node next;
    public node prev;

    public node(int iValue)
    {
        data = iValue;
        next = null;
        prev = null;
    }
}


class DoublyCL
{
    public node First;
    public node Last;
    public int iCount;

    public DoublyCL()
    {
       System.out.println("Object of DoublyCL gets created Successfully"); 
       First = null;
       Last = null;
       iCount = 0; 
    }

    public void InsertFirst(int iNo)
    {
        node newn = null;
        
        newn = new node(iNo);

        if(First == null && Last == null)
        {
            First = newn;
            Last = newn;
        }
        else
        {
            newn.next = First;
            First.prev = newn;
            First = newn;
        }
        Last.next =First;
        First.prev = Last;
        iCount++;
    }

    public void InsertLast(int iNo)
    {
        node newn = null;
        
        newn = new node(iNo);

        if(First == null && Last == null)
        {
            First = newn;
            Last = newn;
        }
        else
        {
            Last.next = newn;
            newn.prev = Last;
            Last = newn;
        }
        Last.next =First;
        First.prev = Last;
        iCount++; 
    }

    public void InsertAtPos(int iNo,int iPos)
    {
       
    }

    public void DeleteFirst()
    {
        if(First == null && Last == null)
        {
            return;
        }
        else if(First == Last)
        {
            First = null;
            Last = null;
        }
        else
        {
            First = First.next;

            Last.next = First;
            First.prev = Last;
            iCount--;
        }
    }

    public void DeleteLast()
    {
       
        if(First == null && Last == null)
        {
            return;
        }
        else if(First == Last)
        {
            First = null;
            Last = null;
        }
        else
        {
            Last = Last.prev;
            
            Last.next = First;
            First.prev = Last;
            iCount--;

        } 
    }

    public void DeleteAtPos(int iPos)
    {
        
    }

    public void Display()
    {
        if(First == null && Last == null)
        {
            System.out.println("LL is empty");
            return;
        }
        do
        {
            System.out.print("| "+First.data+" |<=>");
            First = First.next;
        }while(First != Last.next);
        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }
}

class LinkedList49 
{
    public static void main(String Google[])
    {
        DoublyCL obj = new DoublyCL();
        int iRet = 0;

        obj.InsertFirst(11);
        obj.InsertFirst(21);
        obj.InsertFirst(51);
        obj.InsertFirst(101);
        obj.InsertFirst(111);
        obj.InsertFirst(151);

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteFirst();
        obj.DeleteLast();

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of nodes are : "+iRet);


    }    
}
