class Solution {
public:
    vector<pair<int,int>> curr;
    int row;
    int col;
    void dfs(int i,int j,vector<vector<int>>& grid2)
    {
        if(i<0 or j<0 or i>= row or j>=col )
        {
            return ;
        }
        else if(grid2[i][j]==0)
            return ;
        else if(grid2[i][j]==5) return ;
        else
        {
           grid2[i][j]=5;
           curr.push_back({i,j});
           dfs(i-1,j,grid2);
           dfs(i+1,j,grid2);
           dfs(i,j-1,grid2);
           dfs(i,j+1,grid2);
           return ;
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        row=grid2.size();
        col=grid2[0].size();
        int count=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid2[i][j]==1)
                {
                    dfs(i,j,grid2);
                    bool got=true;
                    for(int i=0;i<curr.size();i++)
                    {
                        if(grid1[curr[i].first][curr[i].second] ==0 )
                        {
                            got=false;
                            break;
                        }
                    }
                    if(got)
                    {
                        ++count;
                    } 
                    curr={};
                }
            }
        }
        return count;
    }
};