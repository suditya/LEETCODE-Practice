class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto i:nums)
        {
            ++mp[i];
            if(mp[i] > (n/3)) {ans.push_back(i); mp[i]=INT_MIN;}
        }
        
        return ans;
    }
};