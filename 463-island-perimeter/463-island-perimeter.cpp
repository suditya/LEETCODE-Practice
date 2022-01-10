class Solution {
public:
    int row;
    int col;
    int land;
    int count;
    int vis[102][102];
    
    bool valid(int i ,int j)
    {
        if(i<0 or j<0 or i>=row or j>=col) return false;
        return true;
    }
    
    void dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(valid(i,j)==false) return ;
        else if(vis[i][j]==1) return ;
        else
        {
            
            vis[i][j]=1;
            ++land;
            cout<<i<<" "<<j<<"\n";
            if(valid(i,j-1) ==true)  //left
            {
                if(grid[i][j-1]==1)
                {
                    count=count+1;
                    if(vis[i][j-1]==0)
                        dfs(i,j-1,grid);
                }
            }
            if(valid(i+1,j) ==true)  //left
            {
                if(grid[i+1][j]==1)
                {
                    count=count+1;
                    if(vis[i+1][j]==0)
                        dfs(i+1,j,grid);
                }
            }
            if(valid(i,j+1) ==true)  //left
            {
                if(grid[i][j+1]==1)
                {
                    count=count+1;
                    if(vis[i][j+1]==0)
                        dfs(i,j+1,grid);
                }
            }
            if(valid(i-1,j) ==true)  //left
            {
                if(grid[i-1][j]==1)
                {
                    count=count+1;
                    if(vis[i-1][j]==0)
                        dfs(i-1,j,grid);
                }
            }
            
            return ;
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        col=grid[0].size();
        row=grid.size();
        count=0;
        land=0;
        for(int i=0;i<102;i++)
        {
            for(int j=0;j<102;j++)
            vis[i][j]=0;
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                    dfs(i,j,grid);
            }
        }
        cout<<land<<" "<<count;
        long ans= 4*(land)-count;
        return int(ans);
    }
};