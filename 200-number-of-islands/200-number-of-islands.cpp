class Solution {
public:
    int row;
    int col;
    void dfs(int x , int y , vector<vector<int>>& vis ,vector<vector<char>>& g)
    {
       
        if((x<0) or  (y<0) or (x>row-1) or (y>col-1)) return ;
        vis[x][y]=1;
        cout<<x<<" "<<y<<"\n";
        
        // if(x!=0 and y!=0 and x!=row-1 and y!=col-1)
        {
            if( ((x-1)>=0) ) //up
            {
                if (vis[x-1][y]==0 and g[x-1][y]=='1' )
                dfs(x-1, y , vis, g);
            }    
            if( ((y-1)>=0) ) //l
            {
                if(g[x][y-1]=='1' and vis[x][y-1]==0)
                    dfs(x, y-1 , vis, g);
            }
            if( (y < col-1) ) //r
               {
                   if( g[x][y+1]=='1' and (vis[x][y+1]==0) )
                    dfs(x, y+1 , vis, g);
               }   
            if( ( x < row-1)) //d
               {   
                   if(g[x+1][y]=='1' and vis[x+1][y]==0)
                   dfs(x+1, y , vis, g);
               }
        }
        // else
        // {
        //     if(x==0 and y==0)
        //     {
        //         if(g[x][y+1]=='1' and vis[x][y+1]==0) //r
        //            dfs(x, y+1 , vis, g);
        //         if(g[x+1][y]=='1' and vis[x+1][y]==0) //d
        //            dfs(x+1, y , vis, g);
        //     }
        //     else  if(x==0)
        //     {
        //          if(g[x][y-1]=='1' and vis[x][y-1]==0) //l
        //             dfs(x, y-1 , vis, g);
        //          if(g[x+1][y]=='1' and vis[x+1][y]==0) //d
        //             dfs(x+1, y , vis, g);
        //          if(g[x][y+1]=='1' and vis[x][y+1]==0) //r
        //             dfs(x, y+1 , vis, g);
        //     } 
        //     else  if(x==0 and y== col-1)
        //     {
        //          if(g[x][y-1]=='1' and vis[x][y-1]==0) //l
        //             dfs(x, y-1 , vis, g);
        //          if(g[x+1][y]=='1' and vis[x+1][y]==0) //d
        //             dfs(x+1, y , vis, g);
        //     }
        //     else  if(x==row-1 and y== 0)
        //     {
        //          if(g[x-1][y]=='1' and vis[x-1][y]==0) //up
        //             dfs(x-1, y , vis, g);
        //          if(g[x][y+1]=='1' and vis[x][y+1]==0) //r
        //             dfs(x, y+1 , vis, g);
        //     }
        //     else  if(x==row-1 and y== col-1)
        //     {
        //          if(g[x][y-1]=='1' and vis[x][y-1]==0) //l
        //             dfs(x, y-1 , vis, g);
        //          if(g[x-1][y]=='1' and vis[x-1][y]==0) //up
        //             dfs(x-1, y , vis, g);
        //     }
        //     else ;
            
            
        // }
    }
    
    int numIslands(vector<vector<char>>& g) 
    {
        col=g[0].size();
        row=g.size();
        // cout<<col<<" "<<row;
        // vector<vector<int>> vis;
        // int vis[row][col];
        vector<vector<int>> vis( row , vector<int> (col, 0));
        int ans=0;
        for(int i =0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(g[i][j]=='1' and vis[i][j]==0)
                {
                    // cout<<i<<" "<<j<<" "<<vis[i][j]<<"\n";
                    ++ans;
                    dfs(i,j,vis,g);
                }
            }
        }
        
        return ans;
    }
};