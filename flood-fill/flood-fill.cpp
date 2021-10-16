class Solution {
public:
    int previous=0;
    bool real(int x,int y,vector<vector<int>> px)
    {
      if( x<0 or y<0 or x>=px.size() or y>=px[0].size())
            return false;
        return true;
    }
    void f(vector<vector<int>>& px, int x, int y, int color,vector<vector<int>>& vis)
    {
        if( x<0 or y<0 or x>=px.size() or y>=px[0].size())
            return ;
        else
        {
            vis[x][y]=1;
            px[x][y]=color;
            // if(real(x-1,y-1,px) and vis[x-1][y-1]==0 and px[x-1][y-1]==previous)
            //     f(px, x-1, y-1,color, vis);
            // if(real(x+1,y-1,px) and vis[x+1][y-1]==0 and px[x+1][y-1]==previous)
            //     f(px, x+1, y-1,color, vis);
            // if(real(x-1,y+1,px) and vis[x-1][y+1]==0 and px[x-1][y+1]==previous)
            //     f(px, x-1, y+1,color, vis);
            // if(real(x+1,y+1,px) and vis[x+1][y+1]==0 and px[x+1][y+1]==previous)
            //     f(px, x+1, y+1,color, vis);
            if(real(x,y-1,px) and vis[x][y-1]==0 and px[x][y-1]==previous)
                f(px, x, y-1,color, vis);
            if(real(x+1,y,px) and vis[x+1][y]==0 and px[x+1][y]==previous)
                f(px, x+1, y,color, vis);
            if(real(x,y+1,px) and vis[x][y+1]==0 and px[x][y+1]==previous)
                f(px, x, y+1,color, vis);
            if(real(x-1,y,px) and vis[x-1][y]==0 and px[x-1][y]==previous)
                f(px, x-1, y,color, vis);
            
            return;
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& px, int x, int y, int color) 
    {
        previous=px[x][y];
        vector<vector<int>> vis( px.size() , vector<int> ( px[0].size(), 0));
        // cout<<px[0].size()<<" "<<px.size();
        // vector<vector<int>>()
        // vector<vector<int>> vis( n , vector<int> (m));
        f(px,x,y,color,vis);
        return px;
    }
};