#include <bits/stdc++.h>
using namespace std;
int maxofall(int arr[],int n,int k)
{  int i;
   deque<int>qi;
   for(i=0;i<k;i++)
   {
       while(!qi.empty()&&arr[qi.back()]<=arr[i])
       qi.pop_back();
       qi.push_back(i);
   }
       for(;i<n;i++)
       {
           cout<<arr[qi.front()]<<" ";
           while(!qi.empty()&&qi.front()<=i-k)
           qi.pop_front();
           while(!qi.empty()&&arr[qi.back()]<=arr[i])
           qi.pop_back();
           qi.push_back(i);
       }
       cout<<arr[qi.front()]<<endl;
    
}

int main() {
	         
	    int n,k,i;
	    cin>>n;
	    int arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>k;
	    maxofall(arr,n,k);
	
	return 0;
}