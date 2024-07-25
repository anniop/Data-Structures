import java.util.*;
public class Hashmap4
{
    public static void main(String[] Google) 
    {
        Scanner sobj = new Scanner(System.in);
        
        System.out.println("Enter String : ");
        String str = sobj.nextLine();

        char Arr[] = str.toCharArray();

        HashMap <Character, Integer> hobj = new HashMap<Character, Integer>();

        int Frequency = 0;
        
        for(char ch : Arr)
        {
            if(hobj.containsKey(ch))
            {
                Frequency = hobj.get(ch);
                hobj.put(ch, Frequency+1);
            }
            else
            {
                hobj.put(ch,1);
            }
        }

        Set <Character> setobj =  hobj.keySet();

        for(char data : setobj)
        {
            System.out.println(data+ " occurs " + hobj.get(data )+ " times");
        }
    }    
}
