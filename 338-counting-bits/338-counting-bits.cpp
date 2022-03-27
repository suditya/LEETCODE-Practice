class Solution {
public:
    vector<int> countBits(int n) 
    {
        if(n==0)
            return {0};
        // int dp[n+1];
        vector<int> dp(n+1,0);
        dp[0]=0;
        int offset=1;
        for(int i=1;i<=n;i++)
        {
          if(offset*2 == i)
            offset=offset*2;
          dp[i]=dp[i-offset]+1;
        }
        return dp;
        
    }
};