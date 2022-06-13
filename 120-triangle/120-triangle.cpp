class Solution {
public:
    // int dp[400][400];
    map<pair<int,int>,int> dp;
    int f(vector<vector<int>>& a,int r,int c)
    {
        if(r==a.size()) return 0;
        // else if(dp[r][c]!=-10005) return dp[r][c];
        else if(dp.find({r,c})!=dp.end()) return dp[{r,c}];
        else
        {
            return dp[{r,c}]=min(f(a,r+1,c),f(a,r+1,c+1))+a[r][c];
        }
    }
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        // memset(dp,-10005,sizeof(dp));
        return f(triangle,0,0);   
    }
};