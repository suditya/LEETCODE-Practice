class Solution {
public:
    int count;
    int ans;
    int visited;
    int not_visited;
    int land;
    int water;
    int vis[100][100];
    int row;
    int col;
    
    bool valid(int i,int j)
    {
        if(i<0 or j<0 or i>=row or j>=col)
            return false;
        return true;
    }
    
    void dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(valid(i,j) == false) return ;
        else if(vis[i][j]== visited)
            return ;
        else
        {
            vis[i][j]=visited;
            ++count;
            if(valid(i-1,j) ==true ) //up
            {
                if(grid[i-1][j]==land)
                {
                    dfs(i-1,j,grid);
                }
            }
            if(valid(i,j-1) ==true ) //left
            {
                if(grid[i][j-1]==land)
                {
                    dfs(i,j-1,grid);
                }
            }
            if(valid(i,j+1) ==true ) //right
            {
                if(grid[i][j+1]==land)
                {
                    dfs(i,j+1,grid);
                }
            }
            if(valid(i+1,j) ==true ) //down
            {
                if(grid[i+1][j]==land)
                {
                    dfs(i+1,j,grid);
                }
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        visited=1;
        not_visited=0;
        land=1;
        water=0;
        col=grid[0].size();
        row=grid.size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==land and vis[i][j]== not_visited)
                {
                    count=0;
                    dfs(i,j,grid);
                    ans=max(ans,count);
                }
            }
        }
        return ans;
    }
};