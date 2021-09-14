class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& q) 
    {
        int n=a.size();
        int pf[n];
        pf[0]=a[0];
        for(int i=1;i<n;i++)
        {
            pf[i]=a[i] xor pf[i-1];
        }
        for(int i=0;i<n;i++)
            cout<<pf[i]<<" ";
        vector<int> ans;
        for(int i=0;i<q.size();i++)
        {
            int l=q[i][0];
            int r=q[i][1];
            // cout<<l<<r<<" ";
            if(l==0)
                ans.push_back(pf[r]);
            else if(l==r)
                ans.push_back(a[r]);
            else
            {
                int x=pf[r] xor pf[l-1];
                ans.push_back(x);
            }
        }
        return ans;
        
    }
};