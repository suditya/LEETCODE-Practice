class Solution {
public:
    int ans;
    int row;
    int col;
    int dp[400][400];
    bool isValid(int i,int j)
    {
        if(i<0 or j<0 or i>=row or j>=col) return false;
        return true;
    }
    
    int f(vector<vector<char>>& matrix,int i,int j)
    {
        if(isValid(i,j)==false)
            return 0;
        else if(dp[i][j]!=-1)
            return dp[i][j];
        else
        {
            if(matrix[i][j]=='1')
            {
                return dp[i][j]=min({f(matrix,i+1,j+1),f(matrix,i,j+1),f(matrix,i+1,j)})+1;
            }
            else
                return dp[i][j]=0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        ans=0;
        row=matrix.size();
        col=matrix[0].size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                ans=max(ans,f(matrix,i,j));
            }
        }
        // cout<<ans;
        return (ans*ans);
    }
};