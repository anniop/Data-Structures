import java.util.*;
public class Hashmap10
{
    public static void main(String[] Google) 
    {
        Scanner sobj = new Scanner(System.in);
        
        System.out.println("Enter String : ");
        String str = sobj.nextLine();
        
        str = str.trim();
        str = str.replaceAll("\\s+", " ");
        int Frequency = 0;
        String Arr[] = str.split(" ");
        HashMap<String, Integer> hobj = new HashMap<String, Integer>();
        for(String a : Arr)
        {
            if(hobj.containsKey(a)) // String is already present
            {
                Frequency = hobj.get(a);
                hobj.put(a,Frequency+1);
            }
            else    // String is occured for the first time
            {
                hobj.put(a, 1);
            }
        }

        Set <String>setobj = hobj.keySet();

        int iMax = 0;
        String temp = null;

        for(String B : setobj)
        {
            if(hobj.get(B) > iMax)
            {
                iMax = hobj.get(B);
                temp = B;
            }
        }
        System.out.println(temp + " occured maximum ie " + iMax + " times");

    }    
}
