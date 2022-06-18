class Solution {
public:
    vector<vector<int>> ans;
    int n;
    
    void f(vector<int>& a,int i=0)
    {
        if(i==n)
            ans.push_back(a);
        else
        {
            for(int j=i;j<n;j++)
            {
                swap(a[i],a[j]);
                f(a,i+1);
                swap(a[i],a[j]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        n=nums.size();
        f(nums,0);  
        return ans;
    }
};