#include<bits/stdc++.h>
using namespace std;
int findmaxnumofsumevensub(int a[],int n,int k)
{
	if(n==0)
	return 0;
	if(n==1)
	return a[0]%2==0;
	int ans=0,temp=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		ans++;
		else
		{
			if(i+1<n)
			{
				if(a[i+1]%2==0)
				{
					temp++;
				}
				else
				{
					ans++;
					i++;
				}
				
			}
			else
			{
				if(a[i-1]%2==0)
				temp++;
			}
		}
	}
	return ans+min(k,temp/2);
}
int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<findmaxnumofsumevensub(a,n,k);
}
