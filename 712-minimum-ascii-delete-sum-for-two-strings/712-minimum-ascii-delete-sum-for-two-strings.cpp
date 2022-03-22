class Solution {
public:
    int dp[1500][1500];
    int f(string &s,string &t,int n,int m)
    {
      if(n==0 and m==0)
        return 0;
      else if(dp[n][m]!=-1) { return dp[n][m];}
      else if(n==0 or m==0)
      {
        if(n==0)
        {
          int ans=0;
          for(int x=0;x<m;x++)
          {
            ans+=int(t[x]);
          }
          return dp[n][m]=ans;
        }
        else
        {
          int ans=0;
          for(int x=0;x<n;x++)
          {
            ans+=int(s[x]);
          }
          return dp[n][m]=ans;
        }
      }
      else
      {
        if(s[n-1]==t[m-1])
          return dp[n][m]=f(s,t,n-1,m-1);
        else
          return dp[n][m]=min({f(s,t,n-1,m-1)+int(s[n-1])+int(t[m-1]),f(s,t,n,m-1)+int(t[m-1]),f(s,t,n-1,m)+int(s[n-1]) });
      }
    }
    int minimumDeleteSum(string &s, string &t) 
    {
      memset(dp,-1,sizeof(dp));
      return f(s,t,s.size(),t.size()); 
    }
};