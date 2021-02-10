#include<bits/stdc++.h>

using namespace std;
void wordbreak(string s,string ans,unordered_set<string> st)
{
	if(s.size()==0)
	cout<<ans<<endl;
	string temp;
	for(int i=0;i<s.size();i++)
	{
		temp.push_back(s[i]);
		if(st.find(temp)!=st.end())
		wordbreak(s.substr(i+1,s.size()-i-1),ans+" "+temp+" ",st);
	}
}
int main()
{
	unordered_set<string> s;
	s.insert("i");
	s.insert("like");
	s.insert("sam");
	s.insert("sung");
	s.insert("samsung");
	s.insert("mobile");
	string k="ilikesamsungmobile";
	wordbreak(k,"",s);
}
