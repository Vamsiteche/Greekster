#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n,tempnum,ans=0;
	    bool flag=true;
	    cin>>n;
	    std::vector<vector<long long int> > a;
	    for(long long int i=0;i<n;i++)
	    {
	        vector<long long int> temp;
	        for(long long int j=0;j<n;j++)
	        {
	            cin>>tempnum;
	            temp.push_back(tempnum);
	        }
	        sort(temp.begin(),temp.end());
	        a.push_back(temp);
	    }
	    tempnum=a[n-1][n-1];
	    ans=tempnum;
	    for(long long int i=n-2;i>=0;i--)
	    {
	        long long int j=n-1;
	        while(j>=0)
	        {
	            if(a[i][j]<tempnum)
	            {
	                tempnum=a[i][j];
	                ans+=a[i][j];
	                break;
	            }
	            j--;
	            
	        }
	        if(j<0)
	        {
	            cout<<-1<<endl;
	            flag=false;
	            break;
	        }
	        
	    }
	    if(flag)
	    cout<<ans<<endl;
	}
	return 0;
}

