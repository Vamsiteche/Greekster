#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	stack<int> s;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<n;i++)
	{
		if(!s.empty()&&a[i]==s.top())
		s.pop();
		else
		s.push(a[i]);
	}
	vector<int> ans;
	while(!s.empty())
	{
		ans.push_back(s.top());
		s.pop();
	}
	reverse(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
	cout<<ans[i]<<" ";
}
