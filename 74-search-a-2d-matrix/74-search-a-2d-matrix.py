class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n=len(matrix[0])
        def bs(a:List[int],target: int,i: int,j:int) ->bool:
            if i > j:
                return False
            else:
                mid=i+(j-i)//2
                if a[mid]==target:
                    return True
                elif a[mid] > target:
                    return bs(a,target,i,mid-1)
                else:
                    return bs(a,target,mid+1,j)
        for array in matrix:
            if array[n-1]>=target:
                index = bs(array,target,0,n-1)
                if index == True:
                    return True 
        return False