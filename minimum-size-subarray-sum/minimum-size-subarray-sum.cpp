class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> pf;
        pf.push_back(0);
        for(int i=0;i<n;i++)
        {
            pf.push_back(pf[i]+nums[i]);
        }
        if(pf[n]<target) return 0;
        else
        {
            for(int i=0;i<n;i++)
            {
                if(nums[i]>=target) return 1;
            }
            for(int i=1;i<=n-1;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(j+i <=n)
                    {
                        if(( pf[j+i]-pf[j-1] )>=target)
                            return i+1;
                    }
                    else
                        break;
                }
            }
            return 0;
        }
        
    }
};