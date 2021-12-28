class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) 
    {
        int n=a.size();
        unordered_map <int,int > mp;
        for(int i=0;i<n;i++)
            mp[a[i]]++;
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto i= mp.begin(); i!=mp.end();i++)
        {
            pq.push({i->second,i->first});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while(pq.size() > 0)
        {
            ans.push_back((pq.top()).second);
            pq.pop();
        }
        return ans;
    }
};