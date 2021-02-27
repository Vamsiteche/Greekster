#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	stack<char> st;
	for(int i=0;i<s.size();i++)
	{
		if(st.empty()||(char)st.top()+1!=s[i])
		st.push(s[i]);
		else
		st.pop();
	}
	if(st.empty())
	cout<<"Yes";
	else
	cout<<"No";
}
