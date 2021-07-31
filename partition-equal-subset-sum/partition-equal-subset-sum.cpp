class Solution {
public:
    int dp[202][20002];
    bool canPartition(vector<int>& nums) 
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum=sum+nums[i];
        int n=nums.size();
        if(sum%2==0)
        {
            
            // memset(-1,dp,sizeof(dp));
            return isSubset(nums,n,sum/2);
        }
        else return false;
        
    }
    bool isSubset(vector<int>& a,int n,int sum)
    {
            for(int i=0;i<=sum;i++)
                dp[0][i]=false;
            for(int j=0;j<=n;j++)
                dp[j][0]=true;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=sum;j++)
                {
                    if(a[i-1]<=j)
                    {
                        dp[i][j]=dp[i-1][j-a[i-1]] or dp[i-1][j];
                    }
                    else
                    dp[i][j]=dp[i-1][j];
                }
            }
        return dp[n][sum];
    }
    
};