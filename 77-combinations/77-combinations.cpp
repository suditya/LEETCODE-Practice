class Solution {
public:
    int c;
    vector<vector<int>> ans;
    int realK;
    // map<int,int> dp;
    
    void dfs(int n,int k,vector<int> path,int x=0)
    {
        if(path.size()==realK)
        {
            ans.push_back(path);
            return ;
        }
        else
        {
            ++c;
            // cout<<"\n"<<x<<" ";
            for(int i=1+x;i<=n;i++)
            {
                // int prev=0;
                // if(path.size() > 0) prev=path[path.size()-1]; 
                // if(mp[i]==0 )
                // {
                    // cout<<i<<" ";
                    path.push_back(i);
                    // dp[]
                    // mp[i]=1;
                    dfs(n,k,path,i);
                    // mp[i]=0;
                    path.pop_back();
                    // k=k+1;
                // }
                // cout<<"\n";
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) 
    {
        c=0;
        realK=k;
        vector<int> path;
        // map<int,int> mp;
        // for(int i=1;i<=n;i++) mp[i]=0;
        dfs(n,k,path);
        cout<<c<<" ";
        return ans;
    }
};