#include<iostream>
using namespace std;
int binarysearch(int a[],int n,int target)
{
	if(target<=a[0])
	return 0;
    if(target>a[n-1])
    return n;
	int i=0,j=n-1,mid;
	while(i<=j)
	{
		mid=(i+j)/2;
		if(a[mid]==target)
		return mid;
		if(mid+1<n&&a[mid]<target&&target<a[mid+1])
		return mid+1;
		else if(a[mid]<target)
		i=mid+1;
		else
		j=mid-1;
		
	}
	return n;
}
int main()
{
	int n,target;
	cin>>n>>target;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<binarysearch(a,n,target);
}
