//https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		   string ans;
		   int a[26]={0};
		   int b[26]={0};
		   for(int i=0;i<A.size();i++)
		   {
		       a[A[i]-'a']++;
		       b[A[i]-'a']=i;
		       char c='#';
		       int k=A.size();
		       for(int i=0;i<26;i++)
		       {
		           if(a[i]==1)
		           {
		               if(b[i]<k)
		               {
		                   k=b[i];
		                   c=(char)'a'+i;
		               }
		           }
		       }
		       ans.push_back(c);
		   }
		   return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
