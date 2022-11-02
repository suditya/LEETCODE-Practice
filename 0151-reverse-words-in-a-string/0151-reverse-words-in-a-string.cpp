class Solution {
public:
    string reverseWords(string s) 
    {
        int n= s.size();
        string word="";
        vector<string> v;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                if(word.size() > 0)
                {
                    v.push_back(word);
                    word="";
                }
            }
            else
            {
                word+=s[i];
            }
        }
        
        if(word.size() > 0) v.push_back(word);
        
        reverse(v.begin(), v.end());
        string ans;
        // for(auto i: v) ans=ans+i+" ";
        // cout<<"\n";
        
        int ni=v.size();
        if(ni==0) return ans;
        
        for(int i=0;i<ni-1;i++)
        {
            ans=ans+v[i]+" ";
        }
        ans=ans+v[ni-1];
        
        return ans;
        
        return "";
    }
};