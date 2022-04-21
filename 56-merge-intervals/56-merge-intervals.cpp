class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) 
    {
        sort(v.begin(),v.end());
        int n=v.size();
        if(n<=1) return v;
        int l=0,r=1;
        vector<int> left,right;
        left=v[0];
        right=v[1];
        
        vector<vector<int>> ans;
        while(l<r and r<n)
        {
            if(left[1]>=right[0])
            {
                int li,ri;
                li=min({left[0],right[0]});
                ri=max({right[1],left[1]});
                left={li,ri};
                ++r;
                if(r>=n) break;
                right=v[r];
            }
            else
            {
                ans.push_back(left);
                left=right;
                ++r;
                if(r>=n) break;
                right=v[r];
            }
        }
        ans.push_back(left);
        return ans;
    }
};