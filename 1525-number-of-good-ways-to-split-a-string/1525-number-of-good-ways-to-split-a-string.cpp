class Solution {
public:
    int numSplits(string s) 
    {
        unordered_map<char,int> l,r;
        l[s[0]]++;
        int n=s.size();
        for(int i=1;i<n;i++)
          r[s[i]]++;
        int count=0;
        if(l.size()==r.size())
            ++count;
        for(int i=1;i<n-1;i++)
        {
            l[s[i]]++;
            if(r[s[i]]==1)
            {
                r.erase(s[i]);
                //delete that shit
            }
            else
                r[s[i]]--;
            if(l.size()==r.size())
                ++count;
        }
        return count;
    }
};