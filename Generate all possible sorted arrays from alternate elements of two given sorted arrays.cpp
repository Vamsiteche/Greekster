#include<bits/stdc++.h>
using namespace std;
int binarysearch(int a[],int s,int n,int target)
{
	int i=0,j=n-1;
	int mid;
	while(i<j)
	{
	    mid=(i+j)/2;
		if(a[mid]==target)
		return mid;
		else if(target>a[mid]&&a[mid+1]>=target)
		return mid+1;
		else if(a[mid]<target)
			i=mid+1;
		else
		{
			j=mid-1;
		}
	}
	return -1;
}
void printsort(int a[],int b[],int &n,int &m,int i,int j,bool take,vector<int> ans)
{if(take)
{
	for(int i=0;i<ans.size();i++)
	cout<<ans[i]<<" ";
	cout<<endl;
 } 
if((take&&i>=n)||((!take)&&j>=m))
   {
   	return;
   }
   if(take)
   {
   
	for(int k=i;k<n;k++)
	{
		ans.push_back(a[k]);
		int temp=binarysearch(b,j,m,a[k]);
		if(temp==-1)
		{
		continue;
		}
		else
		{
			printsort(a,b,n,m,i+1,temp,false,ans);
		}
		ans.pop_back();
	}
}
else
   {
	for(int k=j;k<m;k++)
	{
		ans.push_back(b[k]);
		int temp=binarysearch(a,i,n,b[k]);
		if(temp==-1)
		{
			for(int i=0;i<ans.size();i++)
	cout<<ans[i]<<" ";
	cout<<endl;
		  continue;
		}
		else
		{
			
			printsort(a,b,n,m,temp,j+1,true,ans);
			
		}
		ans.pop_back();
	}
}
}
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<m;i++)
	cin>>b[i];
	vector<int> ans;
	printsort(a,b,n,m,0,0,true,ans);
}
