class Solution {
public:
    
    // int dp[100];
    unordered_map<int,int> dp;
    
    bool isHappy(int n) 
    {
        if(n==1)  return true;
        else if(dp.find(n)!=dp.end()) return false;
        else
        {
            dp[n]++;
            int sum=0;
            while(n>0)
            {
                int x=n%10;
                x=x*x;
                n=n/10;
                sum=sum+x;
            }
            return isHappy(sum);
        }
    }
};