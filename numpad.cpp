#include<bits/stdc++.h>
using namespace std;
string a[]={" ","abc","def","ghi","jkl","mno","pqr","stu","vwx","yz"};
void numpad(string &s,int i,string per)
{
	if(i==s.size())
	{
		cout<<per<<" ";
	}
	else
	{
	   for(int j=0;j<a[s[i]-'0'].size();j++)
	   {
	   	per.push_back(a[s[i]-'0'][j]);
	   	numpad(s,i+1,per);
	   	per.pop_back();
	   }
	}
}
int main()
{
	string s;
	cin>>s;
	numpad(s,0,"");
}
