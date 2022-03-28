class Solution {
public:
    map<int,int> dp;
    int f(int n)
    {
        if(n<=1)
            return n;
        // else if(n==1) return 1;
        // else if(dp[n]!=-1)
        //     return dp[n];
        else if(dp.find(n)!=dp.end())
        {
            // cout<<"hi";
            return dp[n];
        }
        else
        {
            int two=1000000009,three=1000000009;
            // if(n%2==0)
                two=f((n/2))+n%2+1;
            // if(n%3==0)
                three=f(n/3)+n%3+1;
            // one=f(n-1);
            return dp[n]=min(two,three);
        }
    }
    
    int minDays(int n) 
    {
        // memset(dp,-1,sizeof(dp));
        // 666666666
        // int dp[n+1];
        // map<int,int> dp;
        // dp[0]=0;
        // dp[1]=1;
        
        return f(n);
    }
};