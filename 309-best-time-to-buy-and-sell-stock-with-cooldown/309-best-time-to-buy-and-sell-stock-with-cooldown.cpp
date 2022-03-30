class Solution {
public:
    int n;
    int dp[5005][2];
    int f(vector<int>& a,int i,bool stock)
    {
        if(i>=n) return 0;
        else if(i==n-1)
        {
            if(stock==true)
                return a[i];
            else
                return 0;
        }
        else if(dp[i][stock]!=-1) 
        {
            // cout<<"hi";
            return dp[i][stock];
        }
        else
        {
            // cout<<i<<" "<<profit<<"\n";
            if(stock==true)
            {
                return dp[i][stock]=max(f(a,i+2,false)+a[i],f(a,i+1,stock));
            }
            else
                return dp[i][stock]=max(f(a,i+1,true)-a[i],f(a,i+1,stock));
        }
    }
    
    int maxProfit(vector<int>& prices) 
    {
        n=prices.size(); 
        memset(dp,-1,sizeof(dp));
        return f(prices,0,false);
    }
};