#include<bits/stdc++.h>
using namespace std;

void lexo(int s,int n)
{
	cout<<s<<" ";
	for(int i=0;i<=9;i++)
	{
		if(10*s+i<=n)
		lexo(10*s+i,n);
	}
	if(s<=9)
	lexo(s+1,n);
}
int main()
{
	int s,n;
	cin>>s>>n;
	lexo(s,n);
}
