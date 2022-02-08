class Solution {
public:
    int n;
    int minIndex(vector<int>& nums,int i,int j)
    {
        if(i==j) return i;
        if(i>j) return -1; 
        {
            int mid=i+(j-i)/2;
            int prev=(mid-1+n)%n;
            int next=(mid+1)%n;
            if(nums[mid] < nums[prev] and nums[mid]< nums[next]) return mid;
            else
            {
                
                if(nums[mid] < nums[j]) //right is sorted
                {
                  return minIndex(nums,0,mid-1);
                }
                else
                  return minIndex(nums,mid+1,j);
            }
        }
    }
    
    int findMin(vector<int>& nums) 
    {
        n=nums.size();
        return nums[minIndex(nums,0,nums.size()-1)];
    }
};