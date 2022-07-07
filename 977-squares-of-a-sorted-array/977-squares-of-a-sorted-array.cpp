class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) 
    {
        int n=a.size();
        // int l=-1,r=-1;
        int pivot=-1;
        for(int i=0;i<n;i++)
        {
            if(a[i]<0) ++pivot;
            a[i]=a[i]*a[i];
        }
        
        if(pivot<0) return a;
        cout<<pivot;
        int l=pivot;
        int r=pivot+1;
        vector<int> ans;
        while(l>=0 and r<n)
        {
            if(a[l]<a[r])
            {
                ans.push_back(a[l]);
                --l;
            }
            else
            {
               ans.push_back(a[r]);
                ++r; 
            }
        }
        // for(auto i:a) cout<<i;
        
        while(l>=0)
        {
            ans.push_back(a[l]); --l;
        }
        while(r<n)
        {
            ans.push_back(a[r]);
            ++r; 
        }
        
        return ans;
    }
};