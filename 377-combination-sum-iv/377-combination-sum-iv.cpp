class Solution {
public:
    int dp[1500];
    int f(vector<int>& a, int target,int n)
    {
      if(target==0) return 1;
      else if(n==0) return 0;
      else if(dp[target]!=-1)
        return dp[target];
      else
      {
        int ans=0;
        for(int i=0;i<n;i++)
        {
          if(a[i]<=target)
          {
            ans+=f(a,target-a[i],n);
          }
          else
            break;
        }
        return dp[target]=ans;
      }
    }
  
    int combinationSum4(vector<int>& a, int target) 
    {
        sort(a.begin(),a.end());
        memset(dp,-1,sizeof(dp));
        return f(a,target,a.size());
    }
};