class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        
        for(auto p : mp)
        {
            char c = p.first;
            int freq = p.second;
            pq.push({freq,c});
        }
        
        string ans;
        
        while(pq.size() > 0)
        {
            auto topElem = pq.top();
            pq.pop();
            
            for(int i=0;i< (topElem.first) ; i++)
            {
                ans.push_back(topElem.second);
            }
            
        }
        
        return ans;
    }
};