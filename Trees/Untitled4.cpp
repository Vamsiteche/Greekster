#include<iostream>
#include<fstream>
using namespace std;
bool IsvalidInventoryLevel(string s)
{
	for(int i=0;i<s.size();i++)
	{
		if(!(s[i]>='0'&&s[i]<='9'))
		return false;
	}
	return true;
}
bool IsValidUnitPrice(string s)
{
	int count_dot=0;
	int count_after_dot=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			if(count_dot==1)
			count_after_dot++;
			if(count_after_dot>2)
			return false;
		}
		else if(s[i]=='.')
		{
			count_dot++;
			if(count_dot>1)
			return false;
		}
		else
			return false;
		
	}
	return true;
	
}
bool IsValidSalesType(string s)
{
	if(s.size()==1&&(s[0]=='1'||s[0]=='0'))
	return true;
	
	return false;
}
bool IsValidProductName(string s)
{
	if((s[0]>='a'&&s[0]<='z')||(s[0]>='A'&&s[0]<='Z'))
	return true;
	
	return false;
}
bool IsValidPLU(string s)
{
	if(s.size()>4)
	return false;
	for(int i=0;i<s.size();i++)
	{
		if(!(s[i]>='0'&&s[i]<='9')||!(s[i]>='a'&&s[i]<='z')||!(s[i]>='A'&&s[i]<='Z')
		return false;
	}
	return true;
}
string tokenize(string &s)
{
	int i=0,j=0;
	string token;
	while(j<s.size()&&([j]!=' '||s[j]!='\t'||s[j]!='\n'||s[j]!='\r'))
	j++;
	while(i<s.size()&&(s[i]!=' '||s[i]!='\t'||s[i]!='\n'||s[i]!='\r')
	{
		i++;
	}
	token=s.substr(j,i);
	s=s.substr(i,s.size()-i);
	return token;
}
int main()
{
	string path;
	getline(cin,path);
	ifstream infile(path);
	if(infile.is_open())
	{
		string line;
		cout<<"Checking "<<path<<endl;
		cout<<"--------------------"<<endl
		while(getline(infile,line))
		{
			bool flag=false;
			int token_count=0;
			while(line.size()>0)
			{
				token_count++;
				string token=tokenize(line);
				if(token.size()>0)
				 {
				 	count++;
				 }
				if(token_count==1)
				{
					if(IsValidPLU(token))
					{
						cout<<"Token #"<<token_count<<" is "<<token<<", PLU is valid"<<endl;
					}
					else
					{
						flag=true;
						cout<<"Token #"<<token_count<<" is "<<token<<", PLU is invalid"<<endl;
					}
				}
				if(token_count==2)
				{
					if(IsValidProductName(token))
					{
						cout<<"Token #"<<token_count<<" is "<<token<<", Product name is valid"<<endl;
					}
					else
					{
						flag=true;
						cout<<"Token #"<<token_count<<" is "<<token<<", Product name is invalid"<<endl;
					}
				}
				if(token_count==3)
				{
					if(IsValidSalesType(token))
					{
						cout<<"Token #"<<token_count<<" is "<<token<<", Sales type is valid"<<endl;
					}
					else
					{
						flag=true;
						cout<<"Token #"<<token_count<<" is "<<token<<", Sales type is invalid"<<endl;
					}
				}
				if(token_count==4)
				{
					if(IsValidUnitPrice(token))
					{
						cout<<"Token #"<<token_count<<" is "<<token<<", Unit price is valid"<<endl;
					}
					else
					{
						flag=true;
						cout<<"Token #"<<token_count<<" is "<<token<<", Unit price is invalid"<<endl;
					}
				}
				if(token_count==5)
				{
					if(IsValidInventoryLevel(token))
					{
						cout<<"Token #"<<token_count<<" is "<<token<<", Inventory Level is valid"<<endl;
					}
					else
					{
						flag=true;
						cout<<"Token #"<<token_count<<" is "<<token<<", Inventory Level is invalid"<<endl;
					}
				}
			}
			if(token_count>5||token_count<5)
			flag=true;
			cout<<endl;
		}
		if(flag)
				cout<<"######## "<<path<<" has invalid content "<<"########";
			else
				cout<<"######## "<<path<<" has valid content "<<"########";
			cout<<endl;
	}
	else
		cout<<"Failed to open file"<<endl;
	
}
