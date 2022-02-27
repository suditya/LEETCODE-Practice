class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(vector<int>& a,int n,int target,vector<int> path)
    {
        if(n<=0)
        {
            if(target==0)
            ans.push_back(path);
        }
        else
        {
            if(a[n-1]<= target)
            {
                auto temp=path;
                temp.push_back(a[n-1]);
                dfs(a,n,target-a[n-1],temp);
                dfs(a,n-1,target,path);
            }
            else
                dfs(a,n-1,target,path);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> path;
        int n=candidates.size();
        dfs(candidates,n,target,path);
        return ans;
    }
};