class Solution {
public:
    int LCS(vector<int>& a, vector<int>& b, int n, int m)
    {

        // Create DP table
        int dp[n+1][m + 1];
        // int res = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if(i==0 or j==0) dp[i][j]=0;
                else if (a[i - 1] == b[j - 1]) 
                {
                    dp[i][j] = dp[i-1][j - 1]+1 ;
                }
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int maxUncrossedLines(vector<int>& a, vector<int>& b) 
    {
      return LCS(a,b,a.size(),b.size());   
    }
};