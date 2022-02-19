class Solution {
public:
    unordered_map<int,int> mp;
    int max_count;
    
    void f(vector<int>& nums,int n,int prev_or)
    {
        if(n==0) return ;
        else
        {
            int with= ((prev_or|nums[n-1]));
            int without= prev_or;
            // cout<<with<<" "<<without<<"\n";
            f(nums,n-1,with);
            f(nums,n-1,without);
            mp[with]++;
            // mp[without]++;
            max_count=max({max_count,with,without});
        }
    }
    
    int countMaxOrSubsets(vector<int>& nums) 
    {   
        max_count=0;
        int n=nums.size();
        f(nums,n,0);
        return mp[max_count];
    }
};