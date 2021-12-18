class Solution {
public:
    int maxProfit(vector<int>& a) 
    {
        int n=a.size();
        int g[n];
        g[n-1]=-1;
        int max_num=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(a[i] >= max_num)
            {
               g[i]=-1;
                max_num=a[i];
            }
            else
            {
                g[i]=max_num;
            }
        }
        for(auto i:g)
            cout<<i<<" ";
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(g[i]!=-1)
            ans=max(ans,(g[i]-a[i]));
        }
        return ans;
       
    }
};