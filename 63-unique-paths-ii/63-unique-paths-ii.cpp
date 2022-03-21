class Solution {
public:
//     var row;
// var col;
// let cache = {};


// var uniquePathsWithObstacles = function(obstacleGrid) 
// {
//     row=obstacleGrid.length;
//     col=obstacleGrid[0].length;
//     return f(obstacleGrid,0,0);  
// };
    int row;
    int col;
    int f(vector<vector<int>>& grid,int i ,int j)
    {

        if(i<0 || j<0 || i>=row || j>=col)
        {
            return 0;
        }
        else if (dp[i][j]!=-1) 
        {
          // console.log('Fetching from cache');
          // cout<<"what a life\n";
          return dp[i][j];
        }
        else if(grid[i][j]==1) //obstacle
        {
            return 0;
        }
        else if(i==row-1 && j==col-1) return 1;
        else
        {
            return dp[i][j]=(f(grid,i,j+1)+f(grid,i+1,j));
        }
    }
    int dp[200][200];
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        row=grid.size();
        col=grid[0].size();
        memset(dp,-1,sizeof(dp)); 
        return f(grid,0,0);
    }
};