class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void f(vector<int>& a,vector<int> path,int i=0)
    {
        if(i==n)
        {
            ans.push_back(path);
        }
        else
        {
            path.push_back(a[i]);
            f(a,path,i+1);
            path.pop_back();
            int j=i;
            while(j<n)
            {
                if(a[j]!=a[i]) break;
                else ++j;
            }
            f(a,path,j);
        }
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        n=nums.size();
        vector<int> path;
        f(nums,path);
        return ans;
    }
};