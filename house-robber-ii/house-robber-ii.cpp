class Solution {
public:

    
    int dp[1001];
    // map<pair<int,bool>,int> dp;
    int f(vector<int> a, int n)
    {
        // cout<<n<<" "<<a[0]<<"\n";
        int dp[n+1];
        dp[0]=0;
        dp[1]=a[0];
        for(int i=2;i<=n;i++)
            dp[i]=max(dp[i-2]+a[i-1],dp[i-1]);
        return dp[n];
    }
    
    int rob(vector<int>& nums) 
    {
        if(nums.size()==1)
            return nums[0];
        // memset(dp,-1,sizeof(dp));
        // dp[0]=0;
        int an=nums[nums.size()-1];
        // int a0=nums[0];
        // int an1=nums[nums.size()-2];
        // int a1=nums[1];
        nums[nums.size()-1]=0;
        int x=f(nums,nums.size());
        nums[nums.size()-1]=an;
        nums[0]=0;
        int y=f(nums,nums.size());
        return max(x,y);
        
    }
};