class Solution {
public:
    int f(vector<int>& nums, int sum) 
    {
            int dp[nums.size()+1][sum+1];
            int n=nums.size();
            dp[0][0]=1;
            for (int i = 1; i <= sum; i++)
               dp[0][i] = 0;
            for (int i = 1; i <= n; i++)
               dp[i][0] = 1;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= sum; j++)
                {
                  // if the value is greater than the sum
                    if (nums[i - 1] > j or nums[i-1]==0)
                        dp[i][j] =dp[i - 1][j];
                    else
                    {
                        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                    }
                }
            }
 
 
            return dp[n][sum];
    }
    
    
    
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        // cout<<f(nums,target)<<" ";
        int sum=0;
        for(int i=0;i<nums.size();i++) sum=sum+nums[i];
        if(target> sum) return 0;
        if((target+sum)%2!=0) return 0;
        int x= f(nums,(target+sum)/2);
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                ++count;
        }
        return pow(2,count)*x;
    }
};