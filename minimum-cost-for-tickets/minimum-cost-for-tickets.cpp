class Solution {
public:
    int x=0;
    // vector<int> dp;
    int dp[400];
    int f(int start ,vector<int>& day, vector<int>& cost)
    {
        // if(start==365) return dp[365];
        if(start > 365) return 0;
//         else if(dp[start]!=-1) 
//         {
            
//             return dp[start];
//         }
        else
        {
            int real_start=0;
            int i=0;
            for(;i<day.size();i++)
            {
                if(day[i]>=start)
                {
                    real_start=day[i];
                    break;
                }
            }
            // cout<<real_start<<" ";
            if(i>=day.size()) return 0;
            if(dp[real_start]!=-1) return dp[real_start];
            // x=real_start;
            else
    return dp[real_start]= 
     min(f(real_start+1,day,cost)+cost[0],min(f(real_start+7,day,cost)+cost[1],f(real_start+30,day,cost)+cost[2]));             
        }
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        for(int i=0;i<400;i++)
        {
            dp[i]=-1;
        }
        dp[365]=min(costs[0],min(costs[1],costs[2]));
        int ans=f(1,days,costs);
         for(int i=0;i<400;i++)
             cout<<dp[i]<<" "<<i<<"\n";
        return ans;
        
    }
};