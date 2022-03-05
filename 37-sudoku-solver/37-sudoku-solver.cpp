class Solution {
public:
    bool isSafe(vector<vector<char>> &board, int i, int j, char val)
    {
        int row = i - i%3, column = j - j%3;
        for(int x=0; x<9; x++) if(board[x][j] == val) return false;
        for(int y=0; y<9; y++) if(board[i][y] == val) return false;
        for(int x=0; x<3; x++)
        for(int y=0; y<3; y++)
            if(board[row+x][column+y] == val) return false;
        return true;
    }
    
    vector<vector<char>> ans;
    void dfs(vector<vector<char>> board,int i,int j)
    {
        if(i==9 and j==0) ans=board;
        else
        {
            if(board[i][j]=='.')
            {
                bool flag=false;
                for(int x='1';x<='9';x++)
                {
                    if(isSafe(board,i,j,x)==true)
                    {
                        flag=true;
                        board[i][j]=x;
                        if(j==8)
                        {
                            dfs(board,i+1,0);
                        }
                        else
                            dfs(board,i,j+1);
                        
                        board[i][j]='.';
                    }
                }
                if(flag==false) return ;
            }
            else
            {
                if(j==8)
                {
                    dfs(board,i+1,0);
                }
                else
                    dfs(board,i,j+1);
            }
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) 
    {
         dfs(board,0,0);
         board=ans;   
    }
};