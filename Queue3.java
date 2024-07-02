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


class Queue
{
    public node First;
    public int iCount;

    public Queue()
    {
        System.out.println("Object of Queue gets created Successfully");
        First = null;
        iCount = 0;
    }

    public void EnQueue(int iNo)
    {
       
        node newn = new node(iNo);

        if(First == null)
        {
            First = newn;
        }
        else
        {
            node temp = First;

            while (temp.next != null) 
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        iCount++;
    }

    public int DeQueue()
    {
        int Value = 0;

        if(First == null)
        {
            System.out.println("Queue is empty");
            return -1;
        }
        else
        {
            Value = First.data;
            First = First.next;
        }
        iCount--;
        return Value;
    }

    public void Display()
    {
       System.out.println("Elements in the Queue are : ");

       node temp = First;

       while(temp != null)
       {
        System.out.println(temp.data+"\t");
        temp = temp.next;
       }

    }

    public int Count()
    {
        return iCount;
    }

   
}

class Queue3
{
    public static void main(String Google[])
    {
        int iRet = 0;
        Queue obj = new Queue();

        obj.EnQueue(10);
        obj.EnQueue(20);
        obj.EnQueue(30);       
        obj.EnQueue(40);

        obj.Display();

        iRet = obj.Count();
        System.out.println("The Number of elements in the Stack are : " + iRet);

       

        iRet = obj.DeQueue();
        System.out.println("Popped Element is : "+iRet );

        obj.Display();
    }    
}
