class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void dfs(vector<int> path,map<int,int> mp)
    {
        if(path.size()>=n)
        {
            ans.push_back(path);
            return ;
        }
        else
        {
           
            for(auto i=mp.begin();i!=mp.end();i++)
            {
                
                if(i->second >= 1) //not taken
                {
                    path.push_back(i->first);
                    // mp[i]=1;
                    i->second=i->second-1;
                    dfs(path,mp);
                    path.pop_back();
                    i->second=i->second+1;
                }
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<int> path;
        map<int,int> mp;
        n=nums.size();
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        // sort(nums.begin(),nums.end());
        dfs(path,mp);
        // vector<vector<int>> v(ans.begin(),ans.end());
        return ans;
    }
};