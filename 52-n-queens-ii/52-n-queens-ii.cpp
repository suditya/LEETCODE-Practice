class Solution {
public:
    int count;
    
    bool isSafe(vector<vector<char>>& b,int i,int j,int n)
    {
        if(j==0) return true;
        else
        {
            // if(b[i][j-1]=='Q') return false;
            // if(i>0 and j>0)
            // {
            //     if(b[i-1][j-1]=='Q') return false;
            // }
            // if(j>0 and i<n-1)
            // {
            //     if(b[i+1][j-1]=='Q') return false;
            // }
            int r=i,c=j;
            
            while(c>=0) //horizontal-to-left
            {
                if(b[r][c]=='Q') return false;
                --c;
            }
            r=i;
            c=j;            
            while(r>=0 and c>=0)  
            {
                if(b[r][c]=='Q') return false;
                --r;--c;
            }
            while(i<n and j>=0)
            {
                if(b[i][j]=='Q') return false;
                ++i; --j;
            }
            return true;
        }
    }
    
    void dfs(vector<vector<char>> board,int Q,int col,int n)
    {
        if(col==n)
        {
            if(Q==0)
                ++count;
            // for(auto x:board)
            // {
            //     for(auto v:x)
            //         cout<<v<<" ";
            //     cout<<"\n";
            // }
            return ;
        }
        else
        {
            int row=n;
            for(int i=0;i<row;i++)
            {
                if(isSafe(board,i,col,n))
                {
                    // cout<<i<<" "<<col<<"\n";
                    board[i][col]='Q';
                    --Q;
                    dfs(board,Q,col+1,n);
                    board[i][col]='.';
                    ++Q;
                }
            }
        }
    }
    
    int totalNQueens(int n) 
    {
        count=0; 
        vector<vector<char>> board( n , vector<char> (n, '.'));
        dfs(board,n,0,n);
        return count;
    }
};