class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        vector<int> sum;
        int s=0;
        int n=nums.size();
        sum.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            s=s+nums[i];
            sum.push_back(s);
        }
        // s.push_back(0);
        for(int i=1;i<=n;i++)
        {
            if(sum[i-1]==(sum[n]-sum[i]))
                return (i-1);
        }
        return -1;
        
        
    }
};