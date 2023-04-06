class Solution {
public:
    int mySqrt(int x) 
    {
        if(x<=0) return 0;
        int ans = 1;
        if(x<=3) return ans;
        int low = 1;
        int high = x/2;
        cout<<x;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            int div = (x/mid);
            if(div == mid)
                return mid;
            else if(mid < div)
            {
                ans = max(ans, mid);
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        
        return ans ;
    }
};