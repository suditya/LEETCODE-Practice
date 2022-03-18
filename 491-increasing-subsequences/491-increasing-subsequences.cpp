class Solution {
public:
    
    set<vector<int>> ans;
    int n;
    void f(int i,int size,vector<int>& a,vector<int> path,int prev)
    {
        if(i==n)
        {
            if(size>=2)
                ans.insert(path);
            return ;
        }
        else
        {
            if(a[i]>=prev)
            {
                path.push_back(a[i]);
                f(i+1,size+1,a,path,a[i]);
                path.pop_back();
                f(i+1,size,a,path,prev);
            }
            else
            {
               f(i+1,size,a,path,prev); 
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        n=nums.size();
        vector<int> path;
        f(0,0,nums,path,-105);
        vector<vector<int>> v(ans.begin(),ans.end());
        return v;
    }
};