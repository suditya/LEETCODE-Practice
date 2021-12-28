class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) 
    {
        priority_queue<pair<int,int>> pq;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            // pq.push({((abs(a[i]-x)),a[i])});
            int w= abs(a[i]-x);
            pq.push({w,a[i]});
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<int> ans;
        while(pq.size()>0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};