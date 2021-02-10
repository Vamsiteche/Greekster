#include<bits/stdc++.h>
using namespace std;
int count=0;
void HVDmoves(int &n,int &m,int i,int j,string ans)
{
   if(i==n-1&&j==m-1)
   {
   	cout<<ans<<endl;
   	return;
   }
   if(i>=n||j>=m)
   {
   	return;
   }
   HVDmoves(n,m,i+1,j,ans+"V");
   HVDmoves(n,m,i,j+1,ans+"H");
   HVDmoves(n,m,i+1,j+1,ans+"D");
   
}
int main()
{
	int n,m;
	cin>>n>>m;
	HVDmoves(n,m,0,0,"");
}
