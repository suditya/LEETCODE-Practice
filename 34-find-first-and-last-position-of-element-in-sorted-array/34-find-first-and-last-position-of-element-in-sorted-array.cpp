class Solution {
public:
    int first;
    int last;
    
    void f(vector<int>& nums, int target,int i,int j)
    {
        if(i>j) return ;
        else
        {
            int mid = i+(j-i)/2;
            if(nums[mid]==target)
            {
                first=min(first,mid);
                f(nums,target,i,mid-1);
            }
            else if(nums[mid] > target)
                f(nums,target,i,mid-1);
            else
                f(nums,target,mid+1,j);
        }
    }
    
    void l(vector<int>& nums, int target,int i,int j)
    {
        if(i>j) return ;
        else
        {
            int mid = i+(j-i)/2;
            if(nums[mid]==target)
            {
                last=max(last,mid);
                l(nums,target,mid+1,j);
            }
            else if(nums[mid] > target)
                l(nums,target,i,mid-1);
            else
                l(nums,target,mid+1,j);
        }
    }
    
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        first=INT_MAX;
        last=INT_MIN;
        f(nums,target,0,nums.size()-1);
        l(nums,target,0,nums.size()-1);
        if(first==INT_MAX or last==INT_MIN) return {-1,-1};
        else return {first,last};
    }
};