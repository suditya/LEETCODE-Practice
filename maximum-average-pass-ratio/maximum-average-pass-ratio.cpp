class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& v, int e) 
    {
        priority_queue< pair<double, pair<int,int>> > pq;
        int n=v.size();
        double sum=0;
        for(int i=0;i<n;i++)
        {
            double x=v[i][0];
            double y=v[i][1];
            double div=(x/y);
            double dif=(((x+1)/(y+1))-(div));
            pq.push({dif,{x,y}});
            
            // cout<<div<<" ";
            sum=sum+div;
            
        }
        // cout<<sum<<" ";
        while(e--)
        {
            double a=pq.top().second.first;
            double b=pq.top().second.second;
            // cout<<a<<" "<<b<<" ";
            sum=sum+(pq.top().first);
            pq.pop();
            pq.push({(((a+2)/(b+2))-((a+1)/(b+1))),{a+1,b+1}});
            // cout<<((a+2)/(b+2))-((a+1)/(b+1))<<" \n";
            // pq.push({(((a+1)/(b+1))-((a)/(b))),{a+1,b+1}});
            
        }
        // cout<<sum<<" ";
        double ans= sum/n;
        return ans;
        
    }
};