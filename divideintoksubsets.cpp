#include<bits/stdc++.h>
using namespace std;
void divideksubset(int a[],int m,int &n,int &k,vector<vector<int> >ans)
{
	if(m==n)
	{
		if(ans.size()!=k)
		return;
		int sum=0;
		for(int i=0;i<ans[0].size();i++)
		sum+=ans[0][i];
		for(int i=0;i<ans.size();i++)
		{
			
		}
		for(int i=0;i<ans.size();i++)
		{
			
			cout<<"(";
			for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";
			cout<<") ";
		}
		cout<<endl;
		return;
	}
	for(int i=0;i<ans.size();i++)
	{
		ans[i].push_back(a[m]);
		divideksubset(a,m+1,n,k,ans);
		ans[i].pop_back();
	}
	vector<int> temp;
	temp.push_back(a[m]);
	ans.push_back(temp);
	divideksubset(a,m+1,n,k,ans);
	ans.pop_back();
 } 

int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	vector<vector<int>>ans;
	divideksubset(a,0,n,k,ans);
}
