class Solution {
public:
    int a, b , c;
    int dp[102][102];
    bool f(string s1, string s2, string s3,int i,int j,int k)
    {
        if(i==a and b==j)
        {
            return true;
        }
        else if(dp[i][j]!=-1) return dp[i][j];
        else if(i==a)
        {
            if(s2[j]==s3[k]) return dp[i][j]=f(s1,s2,s3,i,j+1,k+1);
            else return dp[i][j]=false;
        }
        else if(j==b)
        {
           if(s1[i]==s3[k]) return dp[i][j]=f(s1,s2,s3,i+1,j,k+1);
           else return dp[i][j]=false;
        }
        else
        {
            if(s1[i]==s3[k]  and s2[j]==s3[k])
            {
                return dp[i][j]=(f(s1,s2,s3,i+1,j,k+1)|f(s1,s2,s3,i,j+1,k+1));
            }
            else if(s1[i]==s3[k])
            {
                return dp[i][j]=f(s1,s2,s3,i+1,j,k+1);
            }
            else if(s2[j]==s3[k])
            {
                return dp[i][j]=f(s1,s2,s3,i,j+1,k+1);
            }
            else return dp[i][j]=false;
        }
        
    }
    
    bool isInterleave(string s1, string s2, string s3) 
    {
        // int a,b,c;
        a=s1.size(),b=s2.size(),c=s3.size();
        if( a+b  ==c )
        {
            memset(dp,-1,sizeof(dp));
            return f(s1,s2,s3,0,0,0);
        }
        else return false;
    }
};