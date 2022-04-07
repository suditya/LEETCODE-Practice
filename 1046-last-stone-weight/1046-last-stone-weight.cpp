class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> pq;
        for(auto x:stones) pq.push(x);
        while(pq.size()>=2)
        {
            int y=pq.top(); pq.pop();
            int x=pq.top(); pq.pop();
            // cout<<x<<" "<<y<<"\n";
            if(x!=y)
            {
                int dif=y-x;
                // cout<<dif<<" "<<x<<" "<<y<<"\n";
                if(dif > 0)
                pq.push(dif);
            }
        }
        if(pq.size()==1)
            return pq.top();
        return 0;
    }
};