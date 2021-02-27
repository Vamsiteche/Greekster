#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	
	int n,m;
	string s1,s2;
	unordered_map<string,vector<string> > mp;
	cin>>n;
	string a[n];
	vector<string> b;
	for(int i=0;i<n;i++)
	{
	vector<string> temp;
	  cin>>a[i];
	  mp[a[i]]=temp;
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>s1>>s2;
		mp[s1].push_back(s2);
		for(int j=0;j<mp[s2].size();j++)
		{
			mp[s1].push_back(mp[s2][j]);
		}
		mp.erase(s2);
	}
	for(int i=0;i<n;i++)
	{
		if(mp.find(a[i])!=mp.end())
		{
			b.push_back(a[i]);
			for(int j=0;j<mp[a[i]].size();j++)
			{
				b.push_back(mp[a[i]][j]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" "<<b[i]<<endl;
		if(a[i]==b[i])
		ans++;
	}
	cout<<ans;
}
	
}
