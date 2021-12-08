class Solution {
public:
    int maxNumberOfBalloons(string text) 
    {
        unordered_map<char,int> mp;
        for(int i=0;i<text.size();i++)
        {
            mp[text[i]]++;
        }
        string s="balon";
        int ans=10005;
        for(int i=0;i<5;i++)
        {
            if(s[i]=='l' or s[i]=='o')
            {
                ans=min(ans,(mp[s[i]]/2));
            }
            else
            {
                ans=min(ans,mp[s[i]]);
            }
        }
        return ans;
    }
};