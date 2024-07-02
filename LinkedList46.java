class node
{
    public int data;
    public  node next;

    public node(int iValue)
    {
        data = iValue;
        next = null;
    }
}
/*
struct node 
{
    int data;
    struct node *next;
};
*/

class SinglyLL
{
    public node First;
    public int iCount;

    public SinglyLL()
    {
        System.out.println("Object of SinglyLL gets created Successfully");
        First = null;
        iCount = 0;
    }

    public void InsertFirst(int iNo)
    {
        node newn = null;

        newn = new node(iNo);

        

        if(First == null)
        {
            First = newn;
        }
        else
        {
            newn.next = First;
            First = newn;
        }
        iCount++;
    }

    public void Display()
    {
        System.out.println("Elements of the linked List are");

        node temp = First;

        while(temp != null)
        {
            System.out.print("| "+temp.data+" |->");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public void InsertLast(int iNo)
    {
        node newn = null;

        newn = new node(iNo);
        node temp = null;

        

        if(First == null)
        {
            First = newn;
        }
        else
        {
            temp = First;

            while (temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        iCount++;
    }

    public int Count()
    {
        return iCount;
    }

    public void DeleteFirst()
    {
        if(First == null)
        {
            System.out.println("The Linked list is empty");
        }
        else
        {
            First = First.next;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        node temp = First;
        if(First == null)
        {
            System.out.println("The Linked list is empty");
        }
        else
        {
            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
        }
        iCount--;
    }

    public void InsertAtPos(int iNo,int iPos)
    {
        int i = 0;
        node newn = null;
        if((iPos < 1) || (iPos > iCount+1))
        {
            System.out.println("Invalid Position");
        }
        else if(iPos == 1)
        {
            InsertFirst(iNo);
        }
        else if(iPos == iCount+1)
        {
            InsertLast(iNo);
        }
        else
        {
            node temp = First;
           newn = new node(iNo);
           newn.data = iNo;
           newn.next = null;

           for(i =1 ;i< iPos-1;i++)
           {
                temp = temp.next;
           }

           newn.next = temp.next;
           temp.next = newn; 
           iCount++;  
        }
       
    }
}

class LinkedList46 
{
    public static void main(String Google[])
    {
        int iRet = 0;
        SinglyLL obj = new SinglyLL();

        obj.InsertFirst(101);
        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        
        obj.Display();

        iRet = obj.Count();
        System.out.println("The Number of elements in the Linked List are : " + iRet);

        obj.InsertLast(151);
        obj.InsertLast(111);
        obj.InsertLast(201);

        obj.Display();

        iRet = obj.Count();
        System.out.println("The Number of elements in the Linked List are : " + iRet);

        obj.DeleteFirst();
        obj.Display();

        iRet = obj.Count();
        System.out.println("The Number of elements in the Linked List are : " + iRet);

        obj.DeleteLast();
        obj.Display();

        iRet = obj.Count();
        System.out.println("The Number of elements in the Linked List are : " + iRet);

        obj.InsertAtPos(105, 5);
        obj.Display();

        iRet = obj.Count();
        System.out.println("The Number of elements in the Linked List are : " + iRet);


    }    
}
