#include<bits/stdc++.h>
using namespace std;
bool sudoku(int a[9][9],int n,int k);
bool checkprentsmall(int a[9][9],int i,int j,int &k,int m)
{
	int l=i,o=j;
	for(i=i-i%k;i<l+k;i++)
	{
	for(j=j-j%k;j<o+k;j++)
	if(a[i][j]==m)
	return false;
}
	return true;	
}
bool checkpresent(int a[9][9],int i,int j,int &n,int m)
{
	for(int k=0;k<n;k++)
	if(a[i][k]==m)
	return false;
	for(int k=0;k<n;k++)
	if(a[k][j]==m)
	return false;
	return true;
}
bool fill(int a[9][9],int i,int j,int n,int k)
{
	for(int m=1;m<=9;m++)
	{
		if(checkpresent(a,i,j,n,m))
		{
			if(checkprentsmall(a,i,j,k,m))
			{
				a[i][j]=m;
				if(sudoku(a,n,k))
				return true;
				a[i][j]=0;
			}
		}
	}
	return false;
}
bool sudoku(int a[9][9],int n,int &k)
{
	int i=0,j=0;
	bool flag=false;
	for(;i<n;i++)
	{
		for(;j<n;j++)
		{
			if(a[i][j]==0)
			{
				flag=true;
				break;
			}
			
		}
		if(flag)
			break;
	}
	if(flag)
			if(fill(a,i,j,n,k))
			return true;
			else
			return false;
	return true;
}
int main()
{
	
	 int grid[9][9]= { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };
         sudoku(grid,9,3);
         
         	for(int i=0;i<9;i++)
            {
            	for(int j=0;j<9;j++)
            	{
            		cout<<grid[i][j]<<" ";
				}
				cout<<endl;
			}
		 
		 
}
