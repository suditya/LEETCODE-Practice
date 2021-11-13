class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        map<int,int> mp;
        for(int i=0;i< nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] >1)
            {
                cout<<nums[i]<<" "<<mp[nums[i]];
                return true;
            }
        }
        return false;
        
    }
};