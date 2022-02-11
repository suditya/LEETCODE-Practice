class Solution:
    def numDecodings(self, s: str) -> int:
        def f(s:str,n:int,dp):
            if dp[n]!=-1:
                return dp[n]
            if n==0:
                return 0
            elif s[n-1]==0:
                return f(s,n-1,dp)
            elif n==1:
                return 1
            elif s[n-1]==0 and s[n-2]==0:
                return 0
            elif n==2:
                x=s[n-2]+s[n-1]
                num=int(x)
                print(num,x)
                if int(s[n-2])>=3 and s[n-1]=='0':
                    print("hi2")
                    return 0
                elif num==10 or num==20:
                    return 1
                elif num<=26:
                    return 2
                else:
                    return 1
            else:
                x=s[n-2]+s[n-1]
                num=int(x)
                print(num,x)
                if int(s[n-2])>=3 and s[n-1]=='0':
                    print("hi2")
                    return 0
                if num==10 or num==20:
                    dp[n]=f(s,n-2,dp)
                    return dp[n]
                elif x=="00":
                    return 0
                elif s[n-2]=='0':
                    print("hi")
                    dp[n]=f(s,n-1,dp)
                    return dp[n]
                elif num<=26:
                    dp[n]=f(s,n-1,dp)+f(s,n-2,dp)
                    return dp[n]
                else:
                    dp[n]=f(s,n-1,dp)
                    return dp[n]
        dp = [-1 for i in range(len(s)+5)]
        if s[0]=='0':
            return 0
        return f(s,len(s),dp)