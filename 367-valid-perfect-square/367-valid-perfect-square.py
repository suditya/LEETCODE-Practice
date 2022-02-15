class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        def bs(i,j,n):
            if i>j:
                return False
            else:
                mid=i+(j-i)//2
                square=mid*mid
                if square==n:
                    return True
                elif square>n:
                    return bs(i,mid-1,n)
                else:
                    return bs(mid+1,j,n)
        if num==1:
            return True
        return bs(1,(num//2),num)