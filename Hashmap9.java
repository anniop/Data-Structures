import java.util.*;
public class Hashmap9
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

        for(String B : setobj)
        {
            System.out.println(B + " occurs " + hobj.get(B)+ " times");
        }


    }    
}
