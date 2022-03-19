class Solution {
public:
    int maxProduct(vector<int>& a) 
    {
        int n=a.size();
        int mini=a[n-1],maxi=a[n-1];
        int ans=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            int tmax,tmin;
            tmax=max({a[i],a[i]*maxi,a[i]*mini});
            tmin=min({a[i],a[i]*mini,a[i]*maxi});
            // cout<<tmax<<" "<<tmin<<"\n";
            maxi=tmax;
            mini=tmin;
            ans=max(ans,tmax);
        }
        // cout<<maxi<<" "<<mini;
        return ans;
    }
};