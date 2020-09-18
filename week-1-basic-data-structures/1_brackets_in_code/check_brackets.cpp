#include <bits/stdc++.h>
using namespace std;
void isbalanced(string exp)
{
    int i;
    char s;
    stack<char>st;
    stack<int>st2;
    int n=exp.size();
    for(i=0;i<n;i++)
    {
        if(exp[i]=='{'||exp[i]=='('||exp[i]=='[')
        {
            st.push(exp[i]);
            st2.push(i);
            
        }
        else if(exp[i]==')')
            {
                if(!st.empty() && st.top()=='(') 
                {
                st2.pop();
                st.pop();
                }
                else
                {
                    cout<<i+1<<endl;
                    return;
                }
            }
            
            else if(exp[i]=='}')
            {
                if(!st.empty() && st.top()=='{')
                {
                st2.pop();
                st.pop();
                }
                else
                {
                    cout<<i+1<<endl;
                    return;
                }
            }
            
            else if(exp[i]==']')
            {
                if(!st.empty() && st.top()=='[')
                {
                st2.pop();
                st.pop();
                }
                else
                {
                    cout<<i+1<<endl;
                    return;
                }
            }
        
            
        }
        if(!st.empty())
        {
            while(st2.size()>1)
            st2.pop();
            cout<<st2.top()+1<<endl;
        }
        else
        cout<<"Success"<<endl;
        return;
    
    
}
int main() {
            
        string exp;
        
        cin>>exp;
        isbalanced(exp);
        
    
    return 0;
	         
}
