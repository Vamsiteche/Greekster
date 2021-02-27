#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	unordered_map<char,short> mp;
	mp['+']=1;
	mp['-']=1;
	mp['*']=2;
	mp['/']=2;
	stack<int> number;
	stack<char> oper;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		number.push(s[i]-'0');
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			while((!oper.empty())&&oper.top()!='('&&mp[oper.top()]>=mp[s[i]])
			{
				
				char temp=oper.top();
				oper.pop();
				int b=number.top();
				number.pop();
				int a=number.top();
				number.pop();
				if(temp=='+')
				a=a+b;
				else if(temp=='-')
				a=a-b;
				else if(temp=='*')
				a=a*b;
				else if(temp=='/')
				a=a/b;
				number.push(a);
			}
			oper.push(s[i]);
			
		}
		else if(s[i]=='(')
		oper.push(s[i]);
		else if(s[i]==')')
		{
			char temp=oper.top();
			oper.pop();
			while(temp!='(')
			{
				int b=number.top();
				number.pop();
				int a=number.top();
				number.pop();
				if(temp=='+')
				a=a+b;
				else if(temp=='-')
				a=a-b;
				else if(temp=='*')
				a=a*b;
				else if(temp=='/')
				a=a/b;
				number.push(a);
			    temp=oper.top();
			    oper.pop();
			}
		}
	}
	while(oper.size()>0)
	{
		int b=number.top();
		number.pop();
		int a=number.top();
		number.pop();
		char temp=oper.top();
		oper.pop();
		if(temp=='+')
				a=a+b;
				else if(temp=='-')
				a=a-b;
				else if(temp=='*')
				a=a*b;
				else if(temp=='/')
				a=a/b;
				number.push(a);
	}
	cout<<number.top();
}
