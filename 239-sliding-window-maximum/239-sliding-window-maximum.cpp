class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) 
    {
        int n=a.size(),i=0,j=0;
        vector<int> ans;
        multiset<int,greater<int>> s;
        while(j<n)
        {
            // cout<<j<<" ";
            if(j-i+1 < k)
            {
                s.insert(a[j]);
                ++j;
            }
            else if(j-i+1 == k)
            {
                s.insert(a[j]);
                // ++j;
                ans.push_back(*(s.begin()));
                s.erase(s.find(a[i]));
                ++i, ++j;
            }
        }
        return ans;                   
    }
};