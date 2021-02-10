#include<bits/stdc++.h>
using namespace std;

int BFS(vector<int> b[],bool visited[],int a[],int n,int i)
{
	int ans=0;
	queue<int> q;
	q.push(i);
	visited[i]=1;
	while(q.size())
	{
		int temp=q.front();
		q.pop();
		ans=ans+a[temp];		
		for(int j=0;j<(int)b[temp].size();j++)
		{
			if(visited[b[temp][j]]==false)
			{
			visited[b[temp][j]]=1;
			q.push(b[temp][j]);
		}
		}
		
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	vector<int> b[n];
	bool visited[n]={0};
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int A,B;
		cin>>A>>B;
		b[A-1].push_back(B-1);
		b[B-1].push_back(A-1);
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			ans=max(ans,BFS(b,visited,a,n,i));
		}
	}
	cout<<ans;
}
