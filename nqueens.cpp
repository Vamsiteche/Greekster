#include<bits/stdc++.h>
using namespace std;
void queens(int i,bool columns[],bool diagonals1[],bool diagonals2[],int &n,vector<string> ans)
{
	if(ans.size()==n)
	for(int i=0;i<ans.size();i++)
	cout<<ans[i]<<endl;
		for(int l=0;l<n;l++)
		{
		   if(columns[l]==false&&diagonals1[i-l+2*n]==false&&diagonals2[i+l]==false)
		   {
		   	columns[l]=true;
		   	diagonals1[i-l+2*n]=true;
		   	diagonals2[i+l]=true;
		   	string temp;
		   	for(int i=0;i<l;i++)
		   	temp.push_back('.');
		   	temp+="*";
		   	for(int i=l+1;i<n;i++)
		   	temp+=".";
		   	ans.push_back(temp);
		   	queens(i+1,columns,diagonals1,diagonals2,n,ans);
		   	ans.pop_back();
		   	columns[l]=false;
		   	diagonals1[i-l+2*n]=false;
		   	diagonals2[i+l]=false;
		   }
		}
}
int nqueens(int &n)
{
	bool rows[n]={0};
	bool columns[n]={0};
	bool diagonals1[4*n-1]={0};
	bool diagonals2[2*n-1]={0};
	vector<string> ans;
	queens(0,columns,diagonals1,diagonals2,n,ans);
}
int main()
{
	int n;
	cin>>n;
	nqueens(n);
}
