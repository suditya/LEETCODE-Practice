class Solution {
public:
    int row;
    int col;
    void dfs( int i , int j , vector<vector<char>>& grid)
    {
        cout<<i<<" "<<j<<"\n";
        if(i<0 or j<0 or i>=row or j>=col ) {
            cout<<"people";
            return ;
        }
        else if(grid[i][j]=='X' or grid[i][j]=='T')
        {
            cout<<"people";
            return ;
        }
        else
        {
            
            grid[i][j]='T';
            dfs(i+1,j,grid);
            dfs(i-1,j,grid);
            dfs(i,j+1,grid);
            dfs(i,j-1,grid);
        }
    }
    
    void solve(vector<vector<char>>& grid) 
    {
        row=grid.size();
        col= grid[0].size();
       
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='O' and (i==0 or j==0 or i==row-1 or j==col-1))
                dfs(i,j,grid);
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='O')
                    grid[i][j]='X';
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='T')
                    grid[i][j]='O';
            }
        }
    }
};