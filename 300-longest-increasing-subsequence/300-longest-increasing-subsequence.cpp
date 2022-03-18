class Solution {
public:
    int lengthOfLIS(vector<int>& a) 
    {
        int n=a.size();
        int dp[n+1];
        dp[n]=0;
        int realAns=0;
        for(int i=n-1;i>=0;i--)
        {
            int ans=1;
            for(int j=i+1;j<n;j++)
            {
                if(a[j]>a[i])
                {
                    ans=max(ans,dp[j]+1);
                    // realAns
                }
            }
            dp[i]=ans;
            realAns=max(realAns,ans);
        }
        // return dp[0];
        return realAns;
    }
};