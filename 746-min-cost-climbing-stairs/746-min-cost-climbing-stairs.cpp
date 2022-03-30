class Solution {
public:
    int dp[1005];
    int f(vector<int>& cost,int i,int n)
    {
        if(i==n-1) return cost[i];
        else if(i==n-2)
        {
            return cost[i];
        }
        else if(dp[i]!=-1) return dp[i];
        else
        {
            return dp[i]=min(f(cost,i+1,n),f(cost,i+2,n))+cost[i];
        }
    }
    
    int minCostClimbingStairs(vector<int>& cost) 
    {
        memset(dp,-1,sizeof(dp));
      return min(f(cost,0,cost.size()),f(cost,1,cost.size()));   
    }
};