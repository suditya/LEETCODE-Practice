class Solution:
    def checkPerfectNumber(self, n: int) -> bool:
        t=n
        if (n&1) !=0:
            return False
        q=int(math.sqrt(n))
        print(q,end="\n")
        for i in range(1,q+1):
            # print(i,end=",")
            if t%i==0:
                print(i,end=",")
                j=(t//i)
                if j<t and j!=i:
                    n=n-j
                n=n-i
        return n==0