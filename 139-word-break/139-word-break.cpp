class Solution {
public:
    int dp[305];
    bool f(string s,vector<string>& dict,int start)
    {
        if(start==s.size()) return true;
        else if(dp[start]!=-1) 
        {
            // cout<<"hi";
            return dp[start];
        }
        else
        {
            for(auto d:dict)
            {
                int l=d.size();
                string temp=s.substr(start,l);
                // cout<<temp<<" "<<d<<"\n";
                if(temp==d)
                {
                    if(f(s,dict,start+l)==true) return dp[start]=true;
                }
            }
            return dp[start]=false;
        }
    }
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        memset(dp,-1,sizeof(dp));
        return f(s,wordDict,0);   
    }
};