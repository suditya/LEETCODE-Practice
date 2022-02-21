class Solution {
public:
    // vector<long long> dp;
    long long dp[100006];
    long long f(long long i,vector<vector<int>>& v)
    {
        if(i>= v.size()) return 0;
        else if (dp[i]!=-1)
        {
            cout<<"hi";
            return dp[i];
        }
        else
        {
            return dp[i]=max(f(i+v[i][1]+1,v)+v[i][0],f(i+1,v));
        }
    }
    
    long long mostPoints(vector<vector<int>>& questions) 
    {
        for(long long i=0;i<questions.size();i++) dp[i]=-1;
        return f(0,questions);
    }
};