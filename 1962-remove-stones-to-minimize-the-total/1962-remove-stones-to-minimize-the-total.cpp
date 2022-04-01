class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        priority_queue<double> pq;
        for(auto i:piles)
            pq.push(i);
        for(int i=0;i<k;i++)
        {
            double x= pq.top();
            pq.pop();
            double f=ceil(x/2);
            // cout<<f<<" ";
            pq.push(f);
        }
        double ans=0;
        while(pq.size() > 0)
        {
            double y=pq.top();
            pq.pop();
            ans=ans+(y);
        }
        return int(ans);
    }
};