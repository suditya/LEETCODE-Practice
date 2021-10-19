class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) 
    {
        int n=a.size();
        int x[n],y[n];
        for(int i=0;i<n;i++)
            x[i]=a[i]+i;
        for(int i=0;i<n;i++)
            y[i]=a[i]-i;
        int gtr[n];
        gtr[n-1]=-50000;
        int max=y[n-1];
        for(int i=n-2;i>=0;i--)
        {
            gtr[i]=max;
            if(y[i]>max) max=y[i];
        }
        for(int i=0;i<n;i++)
            cout<<gtr[i]<<" ";
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(x[i]+gtr[i] > ans)
                ans= x[i]+gtr[i];
        }
        
        
        return ans;
        
    }
};