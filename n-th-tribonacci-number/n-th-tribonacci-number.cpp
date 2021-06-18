class Solution {
public:
    int dp[38]={-1};
    // memset(dp, -1, sizeof(dp));
    int tribonacci(int n) 
    {
        if(n==0)
        {
            dp[0]=0;
            // cout<<"hi";
            return dp[n];
        }    
        if(n==1)
        {
            dp[1]=1;
            return dp[n];
        }
        if(n==2)
        {
            dp[2]=1;
            return dp[n];
        }
        if(dp[n]!=0 and(n>=2))
        {
            // cout<<"hi";
            return dp[n];
        }
        else
        {
            dp[n]=(tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3));
            return dp[n];
        }
    }
};