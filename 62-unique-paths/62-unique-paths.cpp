class Solution {
public:
    // vector<vector<int> dp;
    int dp[102][102];
    
    int f(int m ,int n, int i=0,int j=0)
    {
        if(i<0 or j<0 or i>=m or j>=n) return 0;
        if(i==m-1 and j==n-1) return 1;
        if(i==m-1 or j==n-1) return 1;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        else
        {
            return dp[i][j]=( f(m,n,i,j+1)+ f(m,n,i+1,j));
        }
        
    }
    
    int uniquePaths(int m, int n) 
    {
        // if(m==1 and n==1) return 1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=-1;
            }
        }
        return f(m,n,0,0);
    }
};