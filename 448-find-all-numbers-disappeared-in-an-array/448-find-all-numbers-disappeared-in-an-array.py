class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
            dp={}
            for i in nums:
                    dp[i]=1
            n=len(nums)
            ans=[]
            for i in range(1,n+1):
                if i not in dp:
                    ans.append(i)
            return ans
        