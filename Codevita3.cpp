#include<bits/stdc++.h>
using namespace std;
int colcount(vector<vector<int>> &a,int R,int C)
{
	int ans=0;
	set<pair<int,int>> s;
	set<pair<int,int>> s2;
	pair<int,int> p;
		for(int i=0;i<R;i++)
		{
			if(a[i][0]==6)
			{
				ans++;
				int temp=i;
				while(i<R&&a[i][0]==6)
				i++;
				p={temp,i-1};
				s.insert(p);
			}
		}
	for(int j=1;j<C;j++)
	{
		for(int i=0;i<R;i++)
		{
			if(a[i][j]==6)
			{
				int temp=i;
				while(i<R&&a[i][j]==6)
				i++;
				p={temp,i-1};
				if(s.find(p)==s.end())
				ans++;
				s2.insert(p);
			}
		}
		s=s2;
		s2.clear();
	}
	return ans;
}
int rowcount(vector<vector<int>> &a,int R,int C)
{
	int ans=0;
	set<pair<int,int>> s;
	set<pair<int,int>> s2;
	pair<int,int> p;
	for(int j=0;j<C;j++)
		{
			if(a[0][j]==6)
			{
				ans++;
				int temp=j;
				while(j<C&&a[0][j]==6)
				j++;
				p={temp,j-1};
				s.insert(p);
			}
		}
	for(int i=1;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(a[i][j]==6)
			{
				int temp=j;
				while(j<C&&a[i][j]==6)
				j++;
				p={temp,j-1};
				if(s.find(p)==s.end())
				ans++;
				s2.insert(p);
			}
		}
		s=s2;
		s2.clear();
	}
	return ans;
}
int main()
{
	int R,C,K;
	cin>>R>>C;
	vector<vector<int> >a;
	for(int i=0;i<R;i++)
	{
	vector<int> temp;
	for(int j=0;j<C;j++)
	{
	cin>>K;
	temp.push_back(K);
}
a.push_back(temp);
}
	cout<<min(rowcount(a,R,C),colcount(a,R,C));
}
