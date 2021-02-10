#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		n++;
		if(n==1)
		{
			cout<<1<<endl;
		}
		else if(n==2)
		{
			cout<<2<<endl;
		}
		else if(n==3)
		cout<<4<<endl;
		else
		{
			long long int dp[n+1];
			dp[0]=0;
			dp[1]=1;
			dp[2]=2;
			dp[3]=4;
			for(int i=4;i<=n;i++)
			{
				dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
			}
			cout<<dp[n]<<endl;
		}
	}
}
