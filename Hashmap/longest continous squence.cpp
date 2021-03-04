int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_map<int,bool> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=1;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i]-1)!=mp.end())
            {
                mp[nums[i]]=0;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]==true)
            {
                int j=nums[i];
                while(mp.find(j)!=mp.end())
                 j++;
                ans=max(ans,j-nums[i]);
            }
        }
        return ans;
    }
