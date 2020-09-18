
import java.util.*;
import java.lang.*;
import java.io.*;

public class Main
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		while(t-->0)
		{
		    String s=br.readLine();
		    isbalanced(s);
		}
	}
	static void isbalanced(String s)
	{
	    int n=s.length();
	    Stack<Character> st=new Stack<Character>();
	    Stack<Integer> st2=new Stack<Integer>();
	    for(int i=0;i<n;i++)
	    {
	        char c=s.charAt(i);
	        if(c=='('||c=='{'||c=='[')
	        {
	            st.push(c);
	            st2.push(i);
	        }
	        else if (c==')')
	        {
	            if(!st.isEmpty()&&st.peek()=='(')
	            {
                st2.pop();
                st.pop();
                }
                else
                {
                    System.out.println(i+1);
                    return;
                }
	        }
	        else if (c==']')
	        {
	            if(!st.isEmpty()&&st.peek()=='[')
	            {
                st2.pop();
                st.pop();
                }
                else
                {
                    System.out.println(i+1);
                    return;
                }
	        }
	        else if (c=='}')
	        {
	            if(!st.isEmpty()&&st.peek()=='{')
	            {
                st2.pop();
                st.pop();
                }
                else
                {
                    System.out.println(i+1);
                    return;
                }
	        }
	    }
	    
	    if(!st.isEmpty())
        {
            while(st2.size()>1)
            st2.pop();
            System.out.println(st2.peek()+1);
        }
        else
        System.out.println("Success");
        return;
	}
}
