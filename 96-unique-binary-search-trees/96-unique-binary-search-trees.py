class Solution:
    def numTrees(self, n: int) -> int:
        def f(n):
            if n<=2:
                return n
            elif dp[n]!=-1:
                return dp[n]
            else:
                ans=0
                for i in range(1,n+1):
                    print(i)
                    if i>1 and i<n:
                        ans=ans+f(i-1)*f(n-i)
                    else:
                        ans=ans+f(n-1)
                dp[n]=ans
                return ans
        dp=[-1 for _ in range(n+5)]
        
        return f(n)