class Solution {
public:
    bool ansf=false;
    void helper(vector<int> &nums,int i,int &k,vector<int> ans,int &tsum)
    {
        if(ansf)
            return;
        if(i==nums.size())
        {
            for(int i=1;i<k;i++)
                if(ans[i-1]!=ans[i])
                    return;
            ansf=true;
            return;
        }
        for(int j=0;j<k;j++)
        {
            ans[j]+=nums[i];
            if(ans[j]<=tsum)
            helper(nums,i+1,k,ans,tsum);
            ans[j]-=nums[i];
        }
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<int>ans;
        for(int i=0;i<k;i++)
            ans.push_back(0);
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%k)
            return false;
        sum=sum/k;
        helper(nums,0,k,ans,sum);
        return ansf;
    }
};
