/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.util.*;
public class dic {
	public static String dict(String s)
	{
		String[] lis=s.split("/");
		Stack<String> stack=new Stack<>();
		for(String i:lis)
		{
			if(i.equals(".."))
			{
				if(stack.isEmpty())
				{
					return "Invalid input";
				}
				stack.pop();
			}
			else
			{
				stack.push(i+"/");
			}
				
		}
		StringBuffer ans=new StringBuffer();
		while(!stack.isEmpty())
		{
			ans.append(stack.pop());
		}
		return ans.toString();
		
	}
     public static void main(String args[])
     {
    	 Scanner sc= new Scanner(System.in);
    	String s=sc.next();
    	System.out.println(dict(s));
     }
}
