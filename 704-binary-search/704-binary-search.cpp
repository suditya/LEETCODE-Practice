class Solution {
public:
    
    int f(vector<int>& nums, int target,int start,int end)
    {
        if(start > end) return -1;
        else
        {
            int mid=start+(end-start)/2;
            if(target==nums[mid]) return mid;
            else if(target > nums[mid])
            {
                return f(nums,target,mid+1,end);
            }
            else
                return f(nums,target,start,mid-1);
        }
    }
    
    int search(vector<int>& nums, int target) 
    {
        return f(nums,target,0,nums.size()-1);   
    }
};