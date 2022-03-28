class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int x=0;
        int y=0;
        int n=grid[0].size();
        int m=grid.size();
        vector<vector<int>> dp(201, vector<int> (201, 0));
        return  helper(grid, x,y, dp,m,n);
        
    }
    int helper(vector<vector<int>>& grid,int x,int y,vector<vector<int>> &dp,int m,int n)
    {
        if(dp[x][y]!=0) return dp[x][y];
        if(x>=m or y>=n) return INT_MAX;
        if(x==m-1 and y==n-1)
            return grid[x][y];
        else
        {
            int right=helper(grid,x+1,y,dp,m,n);
            dp[x+1][y]=right;
            int down=helper(grid,x,y+1,dp,m,n);
            dp[x][y+1]=down;
            dp[x][y]=min(right,down)+grid[x][y];
            return dp[x][y];
            
        }
    }
};