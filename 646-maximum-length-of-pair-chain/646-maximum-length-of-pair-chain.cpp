class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        sort(pairs.begin(),pairs.end());
        map<pair<int,int>,int> dp;
        int n=pairs.size();
        int realAns=0;
        for(int i=n-1;i>=0;i--)
        {
            int ans=1;
            int pa=pairs[i][0];
            int pb=pairs[i][1];
            for(int j=i+1;j<n;j++)
            {
                int pc=pairs[j][0];
                int pd=pairs[j][1];
                if(pb < pc)
                {
                    ans=max(ans,dp[{pc,pd}]+1);
                }
            }
            dp[{pa,pb}]=ans;
            realAns=max(realAns,ans);
        }
        return realAns;
    }
};