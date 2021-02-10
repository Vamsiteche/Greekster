#include<iostream>
using namespace std;
int main()
{
	int n,t;
	cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++)
	cin>>a[i];
	cin>>t;
	int i=0,k=-1;
	while(i<n)
	{
		if(a[i]<t)
		swap(a[i],a[++k]);
		i++;
	}
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
