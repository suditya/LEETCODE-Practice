class Solution {
public:
    pair<int,int> bottom;
    int row;
    int col;
    
    void dfs(int i ,int j,vector<vector<int>>& land)
    {
        if(i<0 or j<0 or i>=row or j>=col or land[i][j]!=1 )
            return ;
        else
        {
            land[i][j]=2;
            if(i>= bottom.first)
            {
                if(j>= bottom.second)
                    bottom={i,j};
            }
            dfs(i+1,j,land);
            dfs(i-1,j,land);
            dfs(i,j+1,land);
            dfs(i,j-1,land);
            
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) 
    {
        vector<vector<int>> ans;
        row=land.size();
        col=land[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(land[i][j]==1)
                {
                    vector<int> v;
                    v={i,j};
                    bottom={0,0};
                    dfs(i,j,land);
                    v.push_back(bottom.first);
                    v.push_back(bottom.second);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};