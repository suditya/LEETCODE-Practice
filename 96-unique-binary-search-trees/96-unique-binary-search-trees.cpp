class Solution {
public:
    unordered_map<int,int> dp;
    int numTrees(int n) 
    {
        if(n<=1) return 1;
        else if(dp.find(n)!=dp.end())
            return dp[n];
        else
        {
            int count=0;
            for(int i=1;i<=n;i++)
            {
                int left=i-1;
                int right=n-i;
                count+= numTrees(left)*numTrees(right);
            }
            return dp[n]=count;
        }
    }
};