class Solution:
    def integerBreak(self, n: int) -> int:
        def f(n:int,dp):
            if n==1:
                return 1
            # elif n==2:
            #     return 1
            elif dp[n]!=-1:
                return dp[n]
            else:
                ans=n
                for i in range(1,n):
                    ans=max(ans,(i*f(n-i,dp)))
                dp[n]=ans
                return ans
        rans=0
        dp=[-1 for i in range(0,n+5)]
        for i in range(1,n):
            rans=max(rans,(i*f(n-i,dp)))
        return rans