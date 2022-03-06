class Solution {
public:
    int count;
    int dp[1500][1500];
    int f(string x,string y,int n,int m)
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
    
    int longestCommonSubsequence(string text1, string text2) 
    {
        count=0;
        for(int i=0;i<=text1.size();i++)
        {
            for(int j=0;j<=text2.size();j++)
                dp[i][j]=-1;
        }
        cout<<text1.size()<<" "<<text2.size()<<"\n";
        int ans=f(text1,text2,text1.size(),text2.size()); 
        cout<<count;
        return ans;
    }
};