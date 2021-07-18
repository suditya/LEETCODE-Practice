class Solution {
public:
   
    int numSquares(int n) 
    {
        if(n<=0)
             return 0;
        if(n==1)
             return 1;
        if(n==2)
            return 2;
        else
        {
            int dp[n+1];
            for(int i=0;i<=n;i++) dp[i]=INT_MAX;
            dp[0]=0;
            dp[1]=1;
            dp[2]=2;
            // dp[3]=3;
            // dp[4]=1;
            for(int i=3;i<=n;i++)
            {
                for(int j=1;j*j<=i;j++)
                {
                    dp[i]=min(dp[i],dp[i-(j*j)]+1);
                }
                cout<<i<<" "<<dp[i]<<"\n";
            }
            return dp[n];
        }
    }
   
};