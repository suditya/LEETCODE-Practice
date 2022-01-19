class Solution {
public:
    int dp[300][300];
    int row;
    int col;
    
    int dfs(int i,int j,vector<vector<int>>& matrix)
    {
        if(i<0 or j<0 or i>=row or j>=col) 
        {
            cout<<"hi4"<<i<<j<<"\n";
            return 0;
        }   
        else if(dp[i][j]!=-1)
        {
            cout<<"hi5";
            return dp[i][j];
        }
        else
        {
            cout<<"hi3";
            int ans=0;
            if((i-1)>=0 and matrix[i-1][j] > matrix[i][j])
            {
                ans=max(ans,dfs(i-1,j,matrix));
            }
            if((i+1)<row and matrix[i+1][j] > matrix[i][j])
            {
                ans=max(ans,dfs(i+1,j,matrix));
            }
            if((j-1)>=0 and matrix[i][j-1] > matrix[i][j])
            {
                ans=max(ans,dfs(i,j-1,matrix));
            }
            if((j+1)< col and matrix[i][j+1] > matrix[i][j])
            {
                ans=max(ans,dfs(i,j+1,matrix));
            }
            cout<<ans+1;
            return dp[i][j]=ans+1;
        }
    }
        
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        row=matrix.size();
        col=matrix[0].size();
        int ans=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                dp[i][j]=-1;
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(dp[i][j]==-1)
                {
                    cout<<"hi";
                    ans=max(ans,dfs(i,j,matrix));
                }
                else
                {
                    cout<<"hi2";
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};