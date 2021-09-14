class Solution {
public:
    // int x=0;
    // // int dp[1000][1000];
    // int f(int i,int j, vector<vector<int>> a,int n)
    // {
    //     if(i<0 or j<0 ) return INT_MAX-101;
    //     else if(dp[i][j]!=-1) return dp[i][j];
    //     else if(i<0 or j<0 or j>=n or i>=n) return dp[i][j]=INT_MAX-101;
    //     else if(i==n-1) return dp[i][j]=a[i][j];
    //     else
    //     {
    //         cout<<x+1<<" ";
    //         x=x+1;
    //         return dp[i][j]=min(f(i+1,j-1,a,n),min(f(i+1,j,a,n),f(i+1,j+1,a,n)))+a[i][j];
    //     }
    // }
    
    int minFallingPathSum(vector<vector<int>>& a) 
    {
        int ans=INT_MAX;
        int n=a.size();
        int dp[n+1][n+1];
        memset(dp,101,sizeof(dp));
        // for(int i=0;i<a.size();i++)
        //     ans=min(ans,f(0,i,a,a.size()));
        for(int i=0;i<n;i++)
        {
          dp[n-1][i]=a[n-1][i];  
           cout<<dp[n-1][i]<<" "; 
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(j==0)
                    dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+a[i][j];
                else
                    dp[i][j]=min(dp[i+1][j-1],min(dp[i+1][j+1],dp[i+1][j]))+a[i][j];
                // cout<<dp[i][j]<<" "<<i<<" "<<j<<"\n";
            }
        }
        for(int i=0;i<n;i++)
            ans=min(dp[0][i],ans);
        return ans;
    
        
    }
};