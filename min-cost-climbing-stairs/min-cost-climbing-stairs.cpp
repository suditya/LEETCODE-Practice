class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int x=0;
        int y=1;
        // return min(helper(cost,x),helper(cost,y));
         vector<int> dp(1001,-1);
        // cout<<dp[654]<<" ";
        int a=helper(cost,x,dp);
        int b=helper(cost,y,dp);
        // cout<<a<<" "<<b;
        // for(int i=0;i<dp.size();i++)
        //     cout<<dp[i]<<" "<<i<<"\n";
        return min(a,b);
        
        
    }
    int helper(vector<int>& cost, int x,vector<int> &dp)
    {
        if(dp[x]!=-1)
            return dp[x]; 
        if(x == cost.size()-1)
        {   
            dp[x]=cost[x];
            return dp[x];
        }
        if(x == cost.size()-2 )
        {
            dp[x]=cost[x];
            return dp[x];
        }   
        // if(x==cost.size()==0) return 0;
        if(x<0 or x>cost.size()) return INT_MAX;
        else
        {
            cout<<"hi";
            // dp[x+1]=helper(cost,x+1,dp);
            // dp[x+2]=helper(cost,x+2,dp);
            // dp[x]=min(dp[x+1],dp[x+1])+cost[x];
            dp[x]=min(helper(cost,x+1,dp),helper(cost,x+2,dp))+cost[x];
            return dp[x]; 
        }
    }
};