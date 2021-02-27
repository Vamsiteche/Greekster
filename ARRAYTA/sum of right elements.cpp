#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int sum=0;
    for(int i=0;i<n;i++)
    {
    	sum+=a[i];
    	a[i]=sum;
	}
	int temp=a[0];
	for(int i=1;i<n;i++)
	{
		if(2*i<n)
		a[i]=a[2*i]-temp;
		else
		a[i]=a[n-1]-a[i-1];
	}
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
