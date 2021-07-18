class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        if(s.size()> t.size())
            return false;
        else if( s.size()==t.size())
        {
            if(s==t) return true;
            else
                return false;
        }
        else
        {
            int i=0,j=0;
            for(;i<s.size();i++)
            {
                if(j>=t.size()) break;
                for(;j<t.size();j++)
                {
                    if(s[i]==t[j])
                    {
                        j=j+1;
                        break;
                    }
                }
                // if(j==t.size() and i!=s.size())
                //     return false;
            }
            // if(j)
            if(i==s.size() and j==t.size())
                return (s[s.size()-1]==t[t.size()-1]);
            if(i!=s.size()) return false;
            
            return true;
        }
        
    }
};