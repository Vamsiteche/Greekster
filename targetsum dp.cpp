#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,target;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	cin>>target;
	bool dp[n+1][target+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<target+1;j++)
		{
			if(j==0)
			{
				dp[i][j]=true;
				continue;
			}
			if(i==0)
			{
				dp[i][j]=false;
				continue;
			}
			if(j<a[i-1])
			dp[i][j]=dp[i-1][j];
			else
			dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
		}
	}
	cout<<dp[n][target];
}
