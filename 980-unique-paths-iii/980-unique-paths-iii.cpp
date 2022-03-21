class Solution {
public:
    int row ;
    int col ;
    int count;
    int d;
    void f(vector<vector<int>>& grid,int i,int j, set<pair<int,int>>& path)
    {
      if(i<0 or j<0 or i>=row or j>=col) //invalid
      {
        return ;
      }
      else if(grid[i][j]==2) //end
      {
          // cout<<"hey ";
          // cout<<path.size()<<"\n";
          path.insert({i,j});
          if(path.size()==d)
          {  ++count;
            // for(auto x:path)
            //   cout<<x.first<<" "<<x.second<<" , ";
            //   cout<<"\n";
           
          }
          return ;
      } 
      else if(grid[i][j]==-1) return ; //obstacle
      else
      {
          // cout<<i<<" "<<j<<"\n";
          path.insert({i,j});
          // int l=0,r=0,u=0,d=0;
          if((path.find({i,j-1})!=path.end())==false) //left
          {
            
            path.insert({i,j-1});
            f(grid,i,j-1,path);
            // cout<<i<<" "<<j<<" l "<<l<<"\n";
            path.erase({i,j-1});
          }
          if(!(path.find({i,j+1})!=path.end()))  //right
          {
            
            path.insert({i,j+1});
            f(grid,i,j+1,path);
            // cout<<i<<" "<<j<<" r "<<r<<"\n";
            path.erase({i,j+1});
          }
          if(!(path.find({i-1,j})!=path.end())) //up
          {
            // cout<<"u";
            path.insert({i-1,j});
            f(grid,i-1,j,path);
            // cout<<i<<" "<<j<<" u "<<u<<"\n";
            path.erase({i-1,j});
          }
          if(!(path.find({i+1,j})!=path.end())) //down
          {
            // cout<<"d";
            path.insert({i+1,j});
            f(grid,i+1,j,path);
            // cout<<i<<" "<<j<<" d "<<d<<"\n";
            path.erase({i+1,j});
          }
          // cout<<"\n";
          
          // return (l+r+u+d);
      }
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        count=0;
        row=grid.size();
        col=grid[0].size();
        set<pair<int,int>> path;
        
        
        int obstacles=0;
        // int ans=0;
        int x=0,y=0;
        for(int i=0;i<row;i++)
        {
          for(int j=0;j<col;j++)
          {
            if(grid[i][j]==1) //start
            {
              x=i;
              y=j;
            }
            else if(grid[i][j]==-1) //obstacles
            {
                // cout<<"obsx";
                ++obstacles;
            }
            else
              ;
          }
        }
        
        d=(row*col)-obstacles;
        // cout<<d<<" "<<obstacles<<" "<<x<<" "<<y;
        f(grid,x,y,path);
        return count;
        
    }
};