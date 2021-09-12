class Solution {
public:
    vector<int> intersect(vector<int>& a1, vector<int>& a2) 
    {
        map<int,int> m1,m2;
        set<int> s1,s2;
        for(auto i:a1) m1[i]++;
        for(auto i:a2) m2[i]++;
        for(auto i:a1) s1.insert(i);
        for(auto i:a2) s2.insert(i);
        
        vector<int> ans;
        if(a1.size()<= a2.size())
        {
            for(auto i=s1.begin();i!=s1.end();i++)
            {
                int x=0;
                if(m1[*i] <= m2[*i])
                    x=m1[*i];
                else
                    x=m2[*i];
                for(int j=0;j<x;j++)
                    ans.push_back(*i);
            }
        }
        else
        {
            for(auto i=s2.begin();i!=s2.end();i++)
            {
                int x=0;
                if(m1[*i]<=m2[*i])
                    x=m1[*i];
                else
                    x=m2[*i];
                for(int j=0;j<x;j++)
                    ans.push_back(*i);
            }
        }
        return ans;
        
    }
};