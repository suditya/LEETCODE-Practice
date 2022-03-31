class Solution {
public:
    
    int n;
    int dp[50006][2];
    int charge;
    int f(vector<int>& a,int i,bool stock)
    {
        if(i>=n) return 0;
        else if(dp[i][stock]!=-1)
            return dp[i][stock];
        else
        {
            if(stock==true)
            {
                return dp[i][stock]=max(f(a,i+1,!stock)+a[i]-charge,f(a,i+1,stock));
            }
            else
                return dp[i][stock]=max(f(a,i+1,!stock)-a[i],f(a,i+1,stock));
        }
    }
    
    int maxProfit(vector<int>& prices, int fee) 
    {
        n=prices.size();
        memset(dp,-1,sizeof(dp));
        charge=fee;
        return f(prices,0,false);     
    }
};