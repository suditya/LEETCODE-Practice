class Solution:
    def arrangeCoins(self, n: int) -> int:
        rows,count=1,0
        while n>0:
            n=n-rows
            if n>=0:
                count=count+1
            else:
                break
            rows=rows+1
        return count   
    
        