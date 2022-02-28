class Solution {
public:
    vector<string> ans;
    
    void dfs(string s,int i)
    {
        if(i>=s.size()) {ans.push_back(s); return;}
        else
        {
            char x=s[i];
            auto temp=s;
            if(isdigit(x)==false)
            {
                
                if(isupper(x))
                {
                    temp[i]=tolower(x);
                }
                else
                {
                    temp[i]=toupper(x);
                }
                // cout<<i<<" "<<s<<" "<<temp<<"\n";
                // ans.insert(temp);
                // ans.insert(s);
                dfs(temp,i+1);
                dfs(s,i+1);
            }
            else
                dfs(temp,i+1);
            
        }
    }
    
    vector<string> letterCasePermutation(string s) 
    {
        dfs(s,0);
        // ans.insert(s);
        // vector<string> v(ans.begin(),ans.end());    
        return ans;
    }
};