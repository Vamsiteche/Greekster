#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/nearly-sorted-algorithm/0
int main() {
int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    priority_queue<int,vector<int>,greater<int> > q;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    for(int i=0;i<=k;i++)
	    {
	        q.push(a[i]);
	    }
	    for(int i=k+1;i<n;i++)
	    {
	        a[i-k-1]=q.top();
	        q.pop();
	        q.push(a[i]);
	    }
	    for(int i=k;i>=0;i--)
	    {
	        a[n-i-1]=q.top();
	        q.pop();
	    }
	    for(int i=0;i<n;i++)
	    cout<<a[i]<<" ";
	    cout<<endl;
	}
	
	return 0;
}
