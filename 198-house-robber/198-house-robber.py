class Solution:
    def rob(self, nums: List[int]) -> int:
        def f(a,i,n):
            if i==n-1:
                return a[i]
            elif i==n-2:
                return max(a[i],a[i+1])
            elif dp[i]!=-1:
                print("dp is magical")
                return dp[i]
            else:
                dp[i]=max(f(a,i+2,n)+a[i],f(a,i+1,n))
                return dp[i]
        dp=[-1 for i in range(len(nums)+5)]
        return f(nums,0,len(nums))