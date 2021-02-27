#include<bits/stdc++.h>
using namespace std;
struct Compare
{
    public:
    bool operator() (vector<int> a, vector<int> b)
    {
        return b[1]<a[1];
    }
};
bool cmp(vector<int> a, vector<int> b)
{
    return a[0]<b[0];
}
int solve(vector<vector<int> > &A) {
    if(A.size()<=1)
    return A.size();
    sort(A.begin(),A.end(),cmp);
    int ans=0;
    priority_queue<vector<int>,vector< vector<int> >, Compare> q;
    for(int i=1;i<A.size();i++)
    {
        if(!q.empty()&&q.top()[1]<=A[i][0])
        {
            q.pop();
        }
        q.push(A[i]);
        ans=max(ans,(int)q.size());
    }
    return ans;
}

