class Solution {
public:
    int row;
    int col;
    int dp[60][60];
    
    int f(vector<vector<int>>& grid, vector<vector<int>>& cost,int i,int j)
    {
        if(i==row-1)
        {
            return grid[i][j];
        }
        else if(dp[i][j]!=-1) return dp[i][j];
        else
        {
            int ans=INT_MAX;
            for(int c=0;c<col;c++)
            {
                ans=min(ans,( f(grid,cost,i+1,c)+cost[grid[i][j]][c]+grid[i][j] ));
            }
            return dp[i][j]=ans;
        }
    }
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        row=grid.size();
        col=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=INT_MAX;
        for(int c=0;c<col;c++)
        {
            ans=min(ans,f(grid,moveCost,0,c));
        }
        return  ans;
    }
};