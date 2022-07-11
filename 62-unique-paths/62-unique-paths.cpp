class Solution {
public:
    int dp[102][102];
    int f(int i,int j,int m,int n)
    {
        if(i>=n or j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==n-1 and j==m-1) return 1;
        else
        {
            return dp[i][j]=f(i+1,j,m,n)+f(i,j+1,m,n);
        }
    }
    
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,m,n);
    }
};