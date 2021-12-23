class Solution {
public:
    int row;
    int col;
    int left_down;
    int right_down;
    int vis[200][200];
    int dp[200][200];
    // int valid[1000][1000];
    
    
    bool can_go_down(int i,int j,vector<vector<int>>& grid,int direction)
    {
        // int left_down=-1;
        // int right_down=1;
        // if(i+1 > row) return false;
         cout<<"h7";
        if(i<0 or j<0 or i>=row or j>=col)
        {
            cout<<"hey";
            return false;
        }
         cout<<"h8";
        if(direction == left_down)
        {
            if(j-1 < 0) return false;
            else
            {
                 cout<<"h9";
                if(grid[i][j]!= grid[i][j-1])
                    return false;
                else
                    return true;
            }
        }
        // if(direction== right_down)
        else
        {
             cout<<"h10";
            if(j+1 >= col) return false;
            else
            {
                 cout<<"h11";
                if(grid[i][j]!= grid[i][j+1])
                    return false;
                else
                    return true;
            }
        }
    }

    int dfs2(int i,int j , vector<vector<int>>& grid)
    {
        
        if(i<0 or j<0 or i>=row or j>=col)
        {
            cout<<"hey";
            return -1;
        }
        cout<<i<<" "<<j<<"\n";
       
        if(i==row-1 and j>=0)
        {
            cout<<"q1";
            // if(valid[i][j]==1) {return -1;}
            vis[i][j]=1;
            if(grid[i][j] == left_down)
            {
                // if(i+1 < row)
                if(can_go_down(i,j,grid,-1)== false ) { cout<<"hi4 ";cout<<i<<j<<"\n";return dp[i][j]=  -1;}
                return dp[i][j]=j-1;
            }
            else
            {
                if(can_go_down(i,j,grid,1)== false ) { cout<<"hi3 ";cout<<i<<j<<"\n";return dp[i][j]=  -1;}
                return dp[i][j]=j+1;
            }
        }
        else if(vis[i][j]==1)
            {
                cout<<"q2";
                
                // if(valid[i][j]==1) return -1;
                return dp[i][j];
            }
        else
        {
            // if(valid[i][j]==1) return -1;
            cout<<"q3";
            if(i<0 or j<0 or i>=row or j>=col)
            {
                cout<<"hey";
                return -1;
            }
            cout<<"h1";
            vis[i][j]=1;
             cout<<"h2";
            // cout<<"hi2333";
            // cout<<grid[4][0];
            if(grid[i][j] == left_down)
            {
                 cout<<"h3";
                if(can_go_down(i,j,grid,-1)== false ) { cout<<"hi1 "; cout<<i<<j<<"\n"; return dp[i][j]=  -1;}
                 cout<<"h4";
                return dp[i][j]=dfs2(i+1,j-1,grid);
            }
            else
            {
                 cout<<"h5";
                if(can_go_down(i,j,grid,1)== false ) {cout<<"hi2 "; cout<<i<<j<<"\n";return dp[i][j]=  -1;}
                 cout<<"h6";
                return dp[i][j]=dfs2(i+1,j+1,grid);
            }
        }
    }
    
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        left_down=-1;
        right_down=1;
        vector<int> ans;
        row=grid.size();
        col=grid[0].size();
        cout<<row<<" "<<col<<"\n";
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
               { vis[i][j]=0; }
        }
        // for(int i=0;i<col;i++)
        // {
        //     dfs(0,i,grid);
        // }
       
        
//         for(int i=0;i<row;i++)
//         {
//             for(int j=0;j<col;j++)
//                { vis[i][j]=0;}
//         }
        
//         int x=dfs2(4,0,grid);
//         cout<<x;
     
        // cout<<grid[4][0];
        
        for(int i=0;i<col;i++)
        {
            int end_point=dfs2(0,i,grid);
            ans.push_back(end_point);
        }
        
        
        
        //  for(int i=0;i<row;i++)
        // {
        //     for(int j=0;j<col;j++)
        //     {
        //         cout<<dp[i][j]<<" "<<i<<" "<<j<<"\n";
        //     }
        // }
        return ans;
    }
};