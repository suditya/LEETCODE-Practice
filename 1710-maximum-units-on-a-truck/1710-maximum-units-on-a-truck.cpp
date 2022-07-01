class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int truckSize) 
    {
        // sort(b.begin(),b.end(),greater<int)
        priority_queue<pair<int,int>> pq;
        for(auto v:b)
        {
            int units=v[1];
            int boxNum=v[0];
            pq.push({units,boxNum});
        }
        
        int ans=0;
        
        while(truckSize > 0 and pq.size()>0)
        {
            auto maxUnit=pq.top();
            pq.pop();
            int units=maxUnit.first;
            int numBox=maxUnit.second;
            if(numBox <= truckSize)
            {
                ans+=(numBox*units);
                truckSize-=numBox;
            }
            else
            {
                ans+=(truckSize*units);
                truckSize=0;
            }
        }
        
        return ans;
        
    }
};