// { Driver Code Starts
//https://practice.geeksforgeeks.org/problems/length-unsorted-subarray3022/1
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


//User function template for C++
class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n) {
	    // code here
	    vector<int> ans={0,0};
	    int s=-1,e=-1;
	    for(int i=1;i<n;i++)
	    {
	        if(arr[i]<arr[i-1])
	        {
	        s=i-1;
	        break;
	        }
	    }
	    for(int i=n-2;i>=0;i--)
	    {
	        if(arr[i]>arr[i+1])
	        {
	        e=i+1;
	        break;
	        }
	    }
	    if(s==-1||e==-1)
	    return ans;
	    int minele=INT_MAX;
	    int maxele=INT_MIN;
	    for(int i=s;i<=e;i++)
	    {
	        minele=min(minele,arr[i]);
	        maxele=max(maxele,arr[i]);
	    }
	    for(int i=s-1;i>=0;i--)
	    {
	        if(arr[i]>minele)
	        s=i;
	    }
	    for(int i=e+1;i<n;i++)
	    {
	        if(arr[i]<maxele)
	        e=i;
	    }
	    ans[0]=s;
	    ans[1]=e;
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
  // } Driver Code Ends
