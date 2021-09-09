class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int till=0;
        int max=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            // cout<<till<<"  "<<max<<"||";
            till+=nums[i];
            if(till>max) max=till;
            if(till < 0) till=0;
        }
        return max;
        
    }
    int minSubArray(vector<int>& nums) 
    {
        int till=0;
        int min=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            // cout<<till<<"  "<<max<<"||";
            till+=nums[i];
            if(till<min) min=till;
            if(till > 0) till=0;
        }
        return min;
        
    }
    
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int sum=0;
        // for(auto i:nums)
        //     sum+=nums[i];
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        int x=maxSubArray(nums);
        cout<<x<<" "<<minSubArray(nums);
        int y=(sum- minSubArray(nums));
        if(y==0) return x;
        return max(x,y);
    }
};