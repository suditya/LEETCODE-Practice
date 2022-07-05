class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int,int> mp;
        for(auto i:nums) mp[i]++;
        
        int ans=0;
        
        for(auto i:nums)
        {
            if(mp.find(i-1)!=mp.end())
                continue;
            else
            {
                int count=0;
                int num=i;
                while(1)
                {
                    if(mp.find(num)!=mp.end())
                        ++num, ++count;
                    else break;
                }
                ans=max(ans,count);
            }
        }
        
        return ans;
    }
};