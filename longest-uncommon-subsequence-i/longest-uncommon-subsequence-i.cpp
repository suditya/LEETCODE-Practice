class Solution {
public:
    int lcs(string x,string y,int n,int m)
    {
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++) //where m is zero
            dp[i][0]=0;
        for(int i=0;i<=m;i++) //where n is zero
            dp[0][i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(x[i-1]==y[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    
    int findLUSlength(string a, string b) 
    {
        if(a==b) return -1;
        // else if(a.size()==b.size())
        // {
        //     int l=lcs(a,b,a.size(),b.size());
        //     return max(a.size()-l,b.size()-l);
        // }
        else
        {
            return max(a.size(),b.size());
        }
        
    }
};