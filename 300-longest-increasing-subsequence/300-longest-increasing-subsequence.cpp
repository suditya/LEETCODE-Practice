class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int res=1;
        int n=nums.size();
        int dp[n];
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            int local=1;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j] > nums[i])
                {
                    local=max(local,dp[j]+1);
                }
            }
            dp[i]=local;
            res=max(res,dp[i]);
        }
        return res;
    }
};