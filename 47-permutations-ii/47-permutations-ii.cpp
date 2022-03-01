class Solution {
public:
    set<vector<int>> ans;
    
    void dfs(vector<int>& a,vector<int> path,map<int,int> mp)
    {
        if(path.size()>=a.size())
        {
            ans.insert(path);
            return ;
        }
        else
        {
            int prev=11;
            for(int i=0;i<a.size();i++)
            {
                
                if(mp[i]==0) //not taken
                {
                    path.push_back(a[i]);
                    mp[i]=1;
                    dfs(a,path,mp);
                    path.pop_back();
                    mp[i]=0;
                }
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<int> path;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++) mp[i]=0;
        sort(nums.begin(),nums.end());
        dfs(nums,path,mp);
        vector<vector<int>> v(ans.begin(),ans.end());
        return v;
    }
};