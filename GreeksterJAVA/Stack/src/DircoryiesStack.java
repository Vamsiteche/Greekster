import java.util.*;
public class DircoryiesStack {
	public static String dict(String s)
	{
		String[] lis=s.split("/");
		Stack<String> stack=new Stack<>();
		for(i:lis)
		{
			if(i=="..")
			{
				if(stack.isEmpty())
				{
					return "Invalid input";
				}
				stack.pop();
			}
			else
			{
				stack.push(lis[i]);
			}
				
		}
		StringBuffer ans;
		while(!stack.isEmpty())
		{
			ans.append(stack.pop(lis[i]));
			ans.append("/);
			
		}
		return ans.reverse().toString();
		
	}
     public static void main(String args[])
     {
    	 Scanner sc= new Scanner(System.in);
    	String s=sc.next();
    	System.out.println(dict(s));
     }
}
