class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(vector<int> path,int target,int k,int index=1)
    {
        if(target<0) return ;
        else if(path.size()==k)
        {
            if(target==0) ans.push_back(path);
            return ;
        }
        else
        {
            for(int i=index;i<=9;i++)
            {
                path.push_back(i);
                target-=i;
                dfs(path,target,k,i+1);
                target+=i;
                path.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
      
        if(n>45)
        return {};
        else
        {
            vector<int> path;
            dfs(path,n,k,1);
            return ans;
        }
    }
};