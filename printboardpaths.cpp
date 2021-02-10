#include<bits/stdc++.h>
using namespace std;
void printboardpaths(int s,int &e,string ans)
{
	if(s==e)
	cout<<ans<<endl;
	//if(s>e)// reactive method (time limit excdeed
	//return;
	//for cur+i<=end proactive code
	for(int i=1;i<7&&s+i<=end;i++)
	{
		ans+=to_string(i)+" ";
		printboardpaths(s+i,e,ans);
		ans.pop_back();
		ans.pop_back();
	}
}
int main()
{
	int s,e;
	cin>>s>>e;
	printboardpaths(s,e,"");
}
