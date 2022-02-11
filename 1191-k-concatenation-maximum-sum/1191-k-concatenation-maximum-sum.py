class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        def kadane(arr:List[int]):
            n=len(arr)
            local,ans=0,0
            for i in range(0,n):
                local=local+arr[i]
                ans=max(ans,local)
                if local<0:
                    local=0
            return ans
        if k==1:
            return (kadane(arr)%1000000007)
        else:
            temp=arr
            n=len(arr)
            for i in range(0,n):
                temp.append(arr[i])
            two=kadane(temp)
            if k==2:
                return (two%1000000007) 
            else:
                rightSum,leftSum,globalSum=0,0,0
                l,r=0,0
                for i in range(0,n):
                    r=r+arr[i]
                    rightSum=max(rightSum,r)
                    l=l+arr[n-1-i]
                    leftSum=max(leftSum,l)
                    globalSum=globalSum+arr[i]
                print(leftSum,rightSum,globalSum,n)
                ans=0
                ans=max(two,(leftSum+(k-2)*globalSum+rightSum))
                return (ans%1000000007)