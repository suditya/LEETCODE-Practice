class Solution {
public:
    int dp[60];
    int f(int n)
    {
        if(n<=2) return 1;
        else if(dp[n]!=-1) return dp[n];
        else
        {
            int ans=0;
            for(int i=1;i<=n-1;i++)
            {
                ans=max({ans,i*(max(f(n-i),(n-i)))});
            }
            // cout<<n<<" "<<ans<<"\n";
            return dp[n]=ans;
        }
    }
    
    int integerBreak(int n) 
    {
        memset(dp,-1,sizeof(dp));
        return f(n);   
    }
};