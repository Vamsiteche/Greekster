#include<bits/stdc++.h>
using namespace std;
void lex(string s,int n,int i)
{
  if(i==n)
  {
  	return;
  }
  cout<<s<<" ";
	for(char j='0';j<='9';j++)
	{
		s.push_back(j);
		lex(s,n,i+1);
		s.pop_back();
	}
}
void lexo(string s)
{
   if(s.size()==0)
   return;
   string ans="";
   for(char i='1';i<s[0];i++)
   {
   	ans.push_back(i);
   lex(ans,s.size()-1,0);
   ans.pop_back();
}
lexo(s.substr(1,s.size()));
}
int main()
{
	string n;
	cin>>n;
	lexo(n);
}
