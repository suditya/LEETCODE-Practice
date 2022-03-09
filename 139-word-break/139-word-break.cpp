class Solution {
public:
    map<int,bool> dp;
    bool f(string s,vector<string>& dict,int start)
    {
        if(start == s.size()) return true;
        else if (start > s.size()) return false;
        else if(dp.find(start)!=dp.end())
            return dp[start];
        else
        {
            for(int i=0;i<dict.size();i++)
            {
                int d=dict[i].size();
                string sx=(s.substr(start,d));
                // cout<<sx<<" "<<start<<" "<<d<<"\n";
                // cout<<sx<<" "<<dict[i]<<" "<<start<<" "<<d<<"\n";
                if(s[start]==dict[i][0] and (sx==dict[i]))
                {
                    // cout<<sx<<" "<<dict[i]<<" "<<start<<" "<<d<<" -passed \n";
                    if(f(s,dict,(start+d)))
                        return dp[start]=true;
                }
            }
            return dp[start]=false;
        }
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        return f(s,wordDict,0);   
    }
};