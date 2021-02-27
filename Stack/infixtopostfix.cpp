#include<bits/stdc++.h>
using namespace std;
string infixtopostfix(string s)
{
	string ans="";
	stack<char> st;
	unordered_map<char,short> mp;
	mp['+']=1;
	mp['-']=1;
	mp['*']=2;
	mp['/']=2;
	mp['^']=0;
	mp['%']=2; 
	for(int i=0;i<s.size();i++)
	{
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
		{
			ans.push_back(s[i]);
		}
		else if(mp.find(s[i])!=mp.end())
		{
			while((!st.empty())&&st.top()!='('&&mp[s[i]]<=mp[st.top()])
			{
				ans.push_back(st.top());
				st.pop();
			}
			st.push(s[i]);
		}
		else if(s[i]=='(')
		st.push(s[i]);
		else if(s[i]==')')
		{
			while(st.top()!='(')
			{
				ans.push_back(st.top());
				st.pop();
			}
			st.pop();
		}
		
	}
	while(!st.empty())
		{
			ans.push_back(st.top());
			st.pop();
		}
	return ans;
}
int main()
{
	string s;
	cin>>s;
	cout<<infixtopostfix(s);
}
