class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) 
    {
        int n=h.size();
        int ans=n-1;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<n;i++)
        {
            if(h[i]>h[i-1])
            {
                pq.push(h[i]-h[i-1]);
            }
            if(pq.size()>l)
            {
                int dif=pq.top();
                pq.pop();
                if(b>=dif)
                    b=b-dif;
                else
                {
                    ans=i-1;
                    break;
                }
            }
        }
        return ans;
    }
};