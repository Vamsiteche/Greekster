//https://practice.geeksforgeeks.org/problems/common-elements5420/1#
vector<int> common_element(vector<int>v1,vector<int>v2)
{
    // Your code here
    vector<int> ans;
    int i=0,j=0;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    while(i<v1.size()&&j<v2.size())
    {
        if(v1[i]==v2[j])
        {
            ans.push_back(v1[i]);
            i++;
            j++;
        }
        else if(v1[i]<v2[j])
        {
            i++;
        }
        else
        j++;
    }
    return ans;
}
