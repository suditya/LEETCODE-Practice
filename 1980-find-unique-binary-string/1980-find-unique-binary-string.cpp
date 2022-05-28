class Solution {
public:
    int limit;
    string ans;
    map<string,int>  mp;
    void f(int n,string path)
    {
        if(ans.size()>0) return ;
        if(n==0)
        {
            cout<<path<<" ";
            if(mp.find(path)==mp.end()) //doesnt exist
            {
                ans=path;
            }
            return ;
        }
        else
        {
            path.push_back('1');
            f(n-1,path);
            path.pop_back();
            path.push_back('0');
            f(n-1,path);
            return ;
        }
    }
    
    string findDifferentBinaryString(vector<string>& nums) 
    {
        
        for(auto s:nums)
            mp[s]++;
        limit=nums[0].size();
        string path;
        f(limit,path);
        return ans;
    }
};