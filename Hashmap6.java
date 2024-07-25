import java.util.*;
public class Hashmap6
{
    public static void main(String[] Google) 
    {
        Scanner sobj = new Scanner(System.in);
        
        System.out.println("Enter String : ");
        String str = sobj.nextLine();
        
        str = str.trim();
        str = str.replaceAll("\\s+", " ");

        String Arr[] = str.split(" ");

        for(String a : Arr)
        {
            System.out.println(a);
        }

    }    
}
