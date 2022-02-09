class Solution {
public:
//     int res;
//     int binarySearch(vector<int>& nums, int target,int i,int j)
//     {
//         if(i==j) 
//         {
//             if(nums[i]==target) return i;
//             else if(nums[i] > target) return i-1;
//             else return i+1;
//         }
//         // if(i<j) return -1;
//         else
//         {
        
//             int mid=i+(j-i)/2;
//             // res=min(res,mid);
//             // cout<<nums[mid]<<" ";
//             if(nums[mid]==target) return mid;
//             else if(nums[mid] > target)
//             {
//                return  binarySearch(nums,target,i,mid-1);
//             }
//             else
//                 return binarySearch(nums,target,mid+1,j);
//         }
//     }
    
    int searchInsert(vector<int>& nums, int target) 
    {
        int i=0;
        int j=nums.size()-1;
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid] > target)
            {
                j=mid-1;
            }
            else
                i=mid+1;
        }
        return i;
    }
};