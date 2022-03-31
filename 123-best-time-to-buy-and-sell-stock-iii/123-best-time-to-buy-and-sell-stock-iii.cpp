class Solution {
public:
    int n;
    int dp[100005][3][3];
    int f(vector<int>& a,int i,bool stock,int transaction)
    {
        if(i>=n) return 0;
        else if(transaction == 2) return 0;
        else if(dp[i][stock][transaction]!=-1)
        {
            // cout<<"hi";
            return dp[i][stock][transaction];
        }
        else
        {
            if(stock==true)
            {
                return dp[i][stock][transaction]=max(f(a,i+1,!stock,transaction+1)+a[i],f(a,i+1,stock,transaction));
            }
            else
                return dp[i][stock][transaction]=max(f(a,i+1,!stock,transaction)-a[i],f(a,i+1,stock,transaction));
        }
    }
    
    int maxProfit(vector<int>& prices) 
    {
        n=prices.size();
        memset(dp,-1,sizeof(dp));
        return f(prices,0,false,0);   
    }
};