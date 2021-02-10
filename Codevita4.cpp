#include<bits/stdc++.h>
using namespace std;
struct train
{
	int tno;
	int A;
	int D;
	int f;
};
struct cmpt
{
	bool operator()(train const& a,train const& b)
	{
		if(a.D>b.D)
		return true;
		else if(a.D<b.D)
		return false;
		else
		{
			if(a.f>b.f)
			return true;
			else
			return false;
		}
	}
};
bool cmp(train a,train b)
{
	if(a.A<b.A)
	return true;
	else if(a.A>b.A)
	return false;
	else
	return a.tno<b.tno;
}
int main()
{
	int n;
	cin>>n;
	train a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i].tno;
		cin>>a[i].A;
		cin>>a[i].D;
		a[i].D=a[i].D+a[i].A;
	}
	int anst;
	cin>>anst;
	sort(a,a+n,cmp);
	int count=1;
	unordered_map<int,int> mp;
	mp[1]=1;
	priority_queue<train,vector<train>,cmpt> q;
	a[0].f=1;
	if(a[0].tno==anst)
		cout<<a[0].f<<endl;
	q.push(a[0]);
	for(int i=1;i<n;i++)
	{
		if(q.top().D<a[i].A)
		{
			int t;
			t=q.top().f;
			q.pop();
			mp[t]++;
			a[i].f=t;
			q.push(a[i]);
		}
		else
		{
			count++;
			mp[count]=1;
			a[i].f=count;
			q.push(a[i]);
		}
		if(a[i].tno==anst)
		cout<<a[i].f<<endl;
	}
	int maax=-1;
	set<int> ans;
	for(int i=1;i<=(int)mp.size();i++)
	{
	   if(mp[i]>maax)
	   {
	   	ans.clear();
	   	maax=mp[i];
	   	ans.insert(i);
	   }
	   if(mp[i]==maax)
	   {
	   	 ans.insert(i);
	   }
	}
	for(auto it = ans.begin(); it != ans.end(); ++it)
	cout<<*it<<endl;
}
