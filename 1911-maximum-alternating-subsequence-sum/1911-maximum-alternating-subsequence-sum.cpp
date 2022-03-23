class Solution {
public:
    long long dp[100005][3];
    long long n;
    long long f(vector<int>& a,int i=0,bool even=true)
    {
      if(i==n-1)
      {
        if(even)
        {
          return a[i];
        }
        else
          return 0;
      }
      else if(dp[i][even]!=-1)
        return dp[i][even];
      else
      {
        if(even)
        {
          return dp[i][even]=max(f(a,i+1,false)+a[i],f(a,i+1,even));
        }
        else
          return dp[i][even]=max(f(a,i+1,true)-a[i],f(a,i+1,even));
      }
    }
    
    long long maxAlternatingSum(vector<int>& a) 
    {
      n=a.size();
      memset(dp,-1,sizeof(dp));
      return f(a);
    }
};