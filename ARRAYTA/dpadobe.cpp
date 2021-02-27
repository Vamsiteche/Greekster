#include<bits/stdc++.h>
using namespace std;
int main()
{

	
	
	int n;
	cin>>n;
	long long a[2][n];
	a[0][0]=1;
	a[1][0]=1;
	for(int i=1;i<n;i++)
	{
		a[0][i]=a[0][i-1]+a[1][i-1];
		a[1][i]=a[0][i-1];
	}
	cout<<a[0][n-1]+a[1][n-1]<<endl;
	cout<<a[1][n-1]<<'/'<<a[0][n-1]+a[1][n-1]<<endl;

}
