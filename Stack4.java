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


class Stack
{
    public node First;
    public int iCount;

    public Stack()
    {
        System.out.println("Object of Stack gets created Successfully");
        First = null;
        iCount = 0;
    }

    public void push(int iNo)
    {
        node newn = new node(iNo);

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

    public int pop()
    {
        int Value = 0;

        if(First == null)
        {
            System.out.println("Stack is empty");
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
       System.out.println("Elements in the Stack are : ");

       node temp = First;

       while(temp != null)
       {
        System.out.println(temp.data);
        temp = temp.next;
       }

    }

    public int Count()
    {
        return iCount;
    }
   
}

class Stack4 
{
    public static void main(String Google[])
    {
        int iRet = 0;
        Stack obj = new Stack();

        obj.push(101);
        obj.push(51);
        obj.push(21);
        obj.push(11);
        
        obj.Display();

        iRet = obj.Count();
        System.out.println("The Number of elements in the Stack are : " + iRet);

       

        iRet = obj.pop();
        System.out.println("Popped Element is : "+iRet );

        obj.Display();
    }    
}
