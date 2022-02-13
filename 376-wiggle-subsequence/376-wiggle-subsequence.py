class Solution:
    # x=0
    def wiggleMaxLength(self, nums: List[int]) -> int:
        
        def f(a,i,big,prev):
            # global x
            # x=x+1
            if i>=len(a):
                return 0
            elif prev==-1:
                ans=max({f(a,i+1,True,a[i])+1,f(a,i+1,False,a[i])+1,f(a,i+1,big,-1)})
                dp[(i,big,prev)]=ans
                return ans
            elif (i,big,prev) in dp:
                # print("hi")
                return dp[(i,big,prev)]
            else:
                # print("5",end=",")
                if big==True:
                    if a[i]>prev:
                        ans=max(f(a,i+1,False,a[i])+1,f(a,i+1,big,prev))
                        dp[(i,big,prev)]=ans
                        return ans
                    else:
                        ans=f(a,i+1,big,prev)
                        dp[(i,big,prev)]=ans
                        return ans
                else:
                    if a[i]<prev:
                        ans=max(f(a,i+1,True,a[i])+1,f(a,i+1,big,prev))
                        dp[(i,big,prev)]=ans
                        return ans
                    else:
                        ans=f(a,i+1,big,prev)
                        dp[(i,big,prev)]=ans
                        return ans
        dp={}
        # print(len(nums))
        if len(nums)==1:
            return 1
        elif len(nums)==2:
            if nums[0]!=nums[1]:
                return 2
            else:
                return 1
        else:
            return f(nums,0,True,-1)