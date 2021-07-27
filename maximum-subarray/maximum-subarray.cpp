class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        if(nums.size()==1)
            return nums[0];
        int till=0;
        int max=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            // cout<<till<<"  "<<max<<"||";
            till+=nums[i];
            if(till>max) max=till;
            if(till < 0) till=0;
        }
        return max;
        
    }
};