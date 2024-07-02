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

    public void InserLast(int iNo)
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
}

class LinkedList45 
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

        obj.InserLast(151);
        obj.InserLast(111);
        obj.InserLast(201);

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
    }    
}
