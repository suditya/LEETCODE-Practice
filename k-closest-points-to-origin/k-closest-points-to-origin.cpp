class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) 
    {
        priority_queue<pair<double, pair<int,int>>> pq;
        int n=p.size();
        for(int i=0;i<n;i++)
        {
            double dis=sqrt((p[i][0]*p[i][0] )+ (p[i][1]*p[i][1]));
            pq.push({dis,{p[i][0],p[i][1]}});
            cout<<dis<<" ";
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size() > 0)
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};