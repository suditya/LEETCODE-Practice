class Solution {
public:
    int jump(vector<int>& a) 
    {
        int n=a.size();
        int dp[n];
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            if(i+a[i] >= n-1)
                dp[i]=1;
            else
            {
                int ans=INT_MAX;
                for(int j=i+1;j<n and j<= (i+a[i]);j++)
                {
                    ans=min(ans,dp[j]);
                }
                if(ans==INT_MAX)
                    dp[i]=INT_MAX;
                else
                    dp[i]=ans+1;
            }
        }
        return dp[0];
    }
};