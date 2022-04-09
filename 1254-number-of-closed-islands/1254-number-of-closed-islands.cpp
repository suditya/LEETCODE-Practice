class Solution {
public:
    int row;
    int col;
    
    bool isValid(int i,int j)
    {
        if(i<0 or i>=row or j<0 or j>=col) return false;
        return true;
    }
    bool f(vector<vector<int>>& grid, int i , int j)
    {
        if(!isValid(i,j)) return false;
        else if(grid[i][j]==1 or grid[i][j]==2) return true;
        else if(grid[i][j]==-1) return false;
        else
        {
            bool l,r,u,d;
            grid[i][j]=2;
            l=f(grid,i-1,j);
            r=f(grid,i+1,j);
            d=f(grid,i,j-1);
            u=f(grid,i,j+1);
            return (d&l&u&r);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) 
    {
        row=grid.size();
        col=grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if((i==row-1 or j== col-1) and grid[i][j]==0)
                    grid[i][j]=-1;
            }
        }
        int count=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==0)
                {
                    if(f(grid,i,j)==true) ++count;
                }
            }
        }
        return count;
    }
};