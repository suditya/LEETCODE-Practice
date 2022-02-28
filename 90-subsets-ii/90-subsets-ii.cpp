class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(vector<int>& a,int i, vector<int> path)
    {
        if(i>=a.size())
        {
            ans.push_back(path);
        }
        else
        {
            auto temp=path;
            path.push_back(a[i]);
            dfs(a,i+1,path);
            int x=i;
            while(x<a.size() and a[i]==a[x]  )
                ++x;
            dfs(a,x,temp);
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<int> path;
        dfs(nums,0,path);
        return ans;
    }
};