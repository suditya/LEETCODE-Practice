class Solution {
public:
    map<int,int> dp;
    int f(int n)
    {
        if(n==0)
            return 0;
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
            int one=1000000009,two=1000000009,three=1000000009;
            if(n%2==0)
                two=f(n-(n/2));
            if(n%3==0)
                three=f(n-(2*(n/3)));
            if(n%2!=0 || n%3!=0)
            one=f(n-1);
            return dp[n]=min({one,two,three})+1;
        }
    }
    int minDays(int n) {
        return f(n);
        
    }
};