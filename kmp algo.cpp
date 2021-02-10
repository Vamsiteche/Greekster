#include<bits/stdc++.h>
using namespace std;
void computelps(int lps[],string p,int m)
{
	int i=1,len=0;
	lps[0]=0;
	while(i<m)
	{
		if(p[i]==p[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			len=lps[len-1];
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}
void kmp(string s,string p)
{
	int n=s.size(),m=p.size();
	int lps[m];
	computelps(lps,p,m);
	int i=0,j=0;
	while(i<n)
	{
		if(p[j]==s[i])
		i++,j++;
		else
		{
			if(j!=0)
			j=lps[j-1];
			else
			i++;
		}
		if(j==m)
		{
		cout<<"fount at"<<i-j<<endl;
		j=lps[j-1];
	}
		
	}
}
int main()
{
    string s,pat;
    cin>>s>>pat;
    kmp(s,pat);

}
