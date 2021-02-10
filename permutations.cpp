#include<bits/stdc++.h>
using namespace std;
void per(string s,int i)
{
	if(i==s.size())
	cout<<s<<" ";
for(int j=i;j<s.size();j++)
{
	swap(s[i],s[j]);
	per(s,i+1);
	swap(s[i],s[j]);
}
}
int main()
{
	string s;
	cin>>s;
 per(s,0);
}
