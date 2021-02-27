#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int ans[n];
	stack<int> s;
	for(int i=0;i<n;i++)
	{
		while(!s.empty()&&a[s.top()]<a[i])
		{
			s.pop();
		}
		if(s.empty())
		{
			s.push(i);
			ans[i]=i+1;
		}
		else
		{
			ans[i]=i-s.top();
			s.push(i);
	    }
	}
	for(int i=0;i<n;i++)
	cout<<ans[i]<<" ";
}
