class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(int i,vector<int>& a,vector<int> path)
    {
        if(i>=a.size()) ans.push_back(path);
        else
        {
            auto temp=path;
            path.push_back(a[i]);
            //taken
            dfs(i+1,a,path);
            dfs(i+1,a,temp);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> path;
        dfs(0,nums,path);
        return ans;
    }
};