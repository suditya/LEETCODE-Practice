class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        bool one=false;
        vector<pair<int,int>> v;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                    v.push_back({i,j});
                if(grid[i][j]==1)
                    one =true;
            }
        }
        if(one ==false) return 0;
        int time=0;
        queue<pair<int,int>> q;
        while(v.size()>0)
        {
            ++time;
            for(int i=0;i<v.size();i++)
            {
                cout<<v[i].first<<" "<<v[i].second<<"\n";
                q.push(v[i]);
            }
            cout<<"\n";
            v={};
            while(q.size()>0)
            {
                pair<int,int> p=q.front();
                q.pop();
                int x=p.first;
                int y=p.second;
                if( x-1 >=0)
                {
                    if(grid[x-1][y]==1)
                    {
                        v.push_back({x-1,y});
                        grid[x-1][y]=2;
                    }
                }
                if( x+1 < grid.size())
                {
                    if(grid[x+1][y]==1)
                    {
                        v.push_back({x+1,y});
                        grid[x+1][y]=2;
                    }
                }
                if( y-1 >=0)
                {
                    if(grid[x][y-1]==1)
                    {
                        v.push_back({x,y-1});
                        grid[x][y-1]=2;
                    }
                }
                if( y+1 < grid[0].size())
                {
                    if(grid[x][y+1]==1)
                    {
                        v.push_back({x,y+1});
                        grid[x][y+1]=2;
                    }
                }
    
            }
        }
        bool zero=false;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    return -1;
                // if(grid[i][j]==0)
                //     zero=true;
            }
        }
        
        
        
        return time-1;
        
    }
};