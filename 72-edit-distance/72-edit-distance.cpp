class Solution {
public:
    int LCS(string s, string t, int n, int m)
    {

        // Create DP table
        int dp[n+1][m + 1];
        // int res = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if(i==0 and j==0) dp[i][j]=0;
                else if( j==0)
                {
                    dp[i][j]=i;
                }
                else if(i==0)
                {
                  dp[i][j]=j;
                }
                else if (s[i - 1] == t[j - 1]) 
                {
                    dp[i][j] = dp[i-1][j - 1] ;
                }
                else
                    dp[i][j] = min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1});
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) 
    {
        int ans=LCS(word1,word2,word1.size(),word2.size());
        cout<<ans<<" ";
        return (ans);
    }
};