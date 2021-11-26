class Solution {
public:
    int f(vector<int>& a, int n)
    {
        // if(n==0) return 0;
        // else if(n==1)
        //     return a[n-1];
        // else
        // {
        //     return max(f(a,n-2)+a[n-1],f(a,n-1));
        // }
        int dp[n+1];
        dp[0]=0;
        dp[1]=a[0];
        for(int i=2;i<=n;i++)
            dp[i]=max(dp[i-2]+a[i-1],dp[i-1]);
        return dp[n];
    }
    
    int rob(vector<int>& nums) 
    {
         int n= nums.size();
        int t[1001];
        if(n==1) return nums[0];
        t[0]=nums[0];
        t[1]=max(nums[1],nums[0]);
         
        for( int i=2;i<n;i++)
        {
            t[i]=max((nums[i]+t[i-2]),t[i-1]);
        }
       return t[n-1];
    }   
    
};