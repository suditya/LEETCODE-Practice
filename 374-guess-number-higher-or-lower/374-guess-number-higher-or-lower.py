# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        def bs(i,j):
            if i>j:
                return -1
            else:
                mid=i+(j-i)//2
                res= guess(mid)
                if res==0:
                    return mid
                elif res==1:
                    return bs(mid+1,j)
                else:
                    return bs(i,mid-1)
        return bs(1,n)