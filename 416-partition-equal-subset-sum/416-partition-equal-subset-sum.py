class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        def targetSum(a,n,target):
            if target==0:
                return True
            elif n==0:
                return False
            elif (n,target) in dp:
                return dp[(n,target)]
            else:
                if a[n-1]<=target:
                    ans=(targetSum(a,n-1,target-a[n-1]) or targetSum(a,n-1,target))
                    dp[(n,target)]=ans
                    return ans
                else:
                    ans=targetSum(a,n-1,target)
                    dp[(n,target)]=ans
                    return ans
        totalSum=sum(nums)
        if (totalSum&1)!=0:
            return False
        dp={}
        totalSum=totalSum//2
        return targetSum(nums,len(nums),totalSum)
        