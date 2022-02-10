#User function Template for python3
class Solution:
    
    
                    
    
	def findMaximum(self,arr, n):
	    def bs(a,n,i,j):
            if i>j:
                return -1
            else:
                mid=i+(j-i)//2
                left=0
                right=0
                if mid>0 and mid<n-1:
                    if a[mid]>a[mid-1] and a[mid]>a[mid+1]:
                        return mid
                    elif a[mid]> a[mid-1]:
                        return bs(a,n,mid+1,j)
                    else:
                        return bs(a,n,i,mid-1)
                elif mid==0:
                    if a[mid]>a[mid+1]:
                        return mid
                    else:
                        return bs(a,n,mid+1,j)
                else:
                    if a[mid]>a[mid-1]:
                        return mid
                    else:
                        return bs(a,n,i,mid-1)
	    index=bs(arr,n,0,n-1)
	    return arr[index]
		# code here

#{ 
#  Driver Code Starts
#Initial Template for Python 3





if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findMaximum(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends