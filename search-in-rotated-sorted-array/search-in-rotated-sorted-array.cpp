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
    
    int binarySearch(vector<int>& nums, int target,int i,int j)
    {
        if(i>j) return -1;
        else
        {
        
            int mid=i+(j-i)/2;
            cout<<nums[mid]<<" ";
            if(nums[mid]==target) return mid;
            else if(nums[mid] > target)
            {
                return binarySearch(nums,target,i,mid-1);
            }
            else
                return binarySearch(nums,target,mid+1,j);
        }
    }
    
    int search(vector<int>& nums, int target) 
    {
        n=nums.size();
        int pivot=minIndex(nums,0,nums.size()-1);
        cout<<pivot<<" ";
        if(pivot==-1) return -1;
        // if(nums[pivot]==target) return pivot;
        int x=binarySearch(nums,target,0,pivot-1);
        cout<<x<<":\n";
        if(x>-1) return x;
        else
        {
           int y= binarySearch(nums,target,pivot,n-1);
           cout<<y<<" ";
           return y;
        }
    }
};