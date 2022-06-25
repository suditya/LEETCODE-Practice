class Solution {
public:
    int row;
    int col;
    
    bool backtrack(vector<vector<char>>& b, string &s,int x,int y,int i=0)
    {
        if(i>=s.size()) return true;
        if(x<0 or y<0 or x>=row or y>=col ) return false;
        if(b[x][y]!=s[i] or b[x][y]=='#') 
        {
            // cout<<b[x][y]<<" "<<s[i]<<"\n";
            return false;
        }
        else
        {
            char temp=b[x][y];
            // cout<<temp<<" "<<x<<" "<<y<<"\n";
            b[x][y]='#';
            if(backtrack(b,s,x+1,y,i+1)) return true;
            if(backtrack(b,s,x-1,y,i+1)) return true;
            if(backtrack(b,s,x,y+1,i+1)) return true;
            if(backtrack(b,s,x,y-1,i+1)) return true;
            b[x][y]=temp;
            return false;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        row=board.size();
        col=board[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]==word[0])
                {
                    // cout<<"hi";
                    if(backtrack(board,word,i,j)==true)
                        return true;
                }
            }
        }
        return false;
    }
};