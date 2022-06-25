class Solution {
public:
    char land;
    char water;
    int row;
    int col;
    
    void dfs(vector<vector<char>>& grid,int x,int y)
    {
        if(x<0 or y<0 or x>=row or y>=col or grid[x][y]=='0' or grid[x][y]=='2') return ;
        else
        {
            grid[x][y]='2';
            dfs(grid,x-1,y);
            dfs(grid,x,y-1);
            dfs(grid,x,y+1);
            dfs(grid,x+1,y);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int islands=0;
        land='1';
        water='0';
        row=grid.size();
        col=grid[0].size();
        // vector<vector<int>> vis( row , vector<int> (col, 0));
        
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    ++islands;
                    dfs(grid,i,j);
                }
            }
        }
        return islands;
    }
};