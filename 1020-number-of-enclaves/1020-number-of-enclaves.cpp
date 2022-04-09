class Solution {
public:
    int row;
    int col;
    
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 or j<0 or i>=row or j>=col) return ;
        else if(grid[i][j]==0 or grid[i][j]==2) return ;
        else
        {
            grid[i][j]=2;
            dfs(grid,i-1,j);
            dfs(grid,i+1,j);
            dfs(grid,i,j-1);
            dfs(grid,i,j+1);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) 
    {
        row=grid.size();
        col=grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1 and (i==row-1 or j==col-1 or i==0 or j==0))
                {
                    dfs(grid,i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                // cout<<grid[i][j]<<" ";
                if(grid[i][j]==1)
                {
                    // dfs(grid,i,j);
                    ++count;
                }
            }
            // cout<<"\n";
        }
        return count;
    }
};