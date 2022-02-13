class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        dp={}
        for i in nums:
            if i in dp:
                return i
            dp[i]=1
        return 0
            
        