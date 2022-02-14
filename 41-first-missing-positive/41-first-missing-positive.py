class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        dp={}
        for i in nums:
                dp[i]=1
        for i in range(1,2147483649):
            if i not in dp:
                return i
        return 0
        
        