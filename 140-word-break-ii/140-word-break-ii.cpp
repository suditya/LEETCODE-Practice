class Solution {
public:
    // map<int,bool> dp;
    vector<string> ans;
    void f(string s,vector<string>& dict,int start,string path)
    {
        if(start == s.size()) 
        {
            ans.push_back(path);
            return ;
        }
        else if (start > s.size()) return ;
        // else if(dp.find(start)!=dp.end())
        //     return dp[start];
        else
        {
            for(int i=0;i<dict.size();i++)
            {
                int d=dict[i].size();
                string sx=(s.substr(start,d));
                
                if(s[start]==dict[i][0] and (sx==dict[i]))
                {
                   
                    string temp=path;
                    if(path.size()!=0)
                        temp.push_back(' ');
                    
                    temp=temp+(dict[i]);
                    f(s,dict,(start+d),temp);
                   
                }
            }
            return ;
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        f(s,wordDict,0,"");
        return ans;
    }
};