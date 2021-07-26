class Solution {
public:
    unsigned int climbStairs(int n) 
    {
        if(n<=0) return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        else
        {
            unsigned int dp[n+1];
            dp[n]=1;
            dp[n-1]=2;
            for(int i=n-2;i>=0;i--)
                dp[i]=dp[i+1]+dp[i+2];
            return dp[1];
        }
        
    }
};