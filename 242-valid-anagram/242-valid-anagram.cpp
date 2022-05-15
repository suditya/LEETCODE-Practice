class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char,int> ms,mt;
        for(int i=0;i<s.size();i++)
        {
            ms[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            mt[t[i]]++;
        }
        for(char i='a';i<='z';i++)
        {
            if(ms[i]!=mt[i]) return false;
        }
        return true;
    }
};