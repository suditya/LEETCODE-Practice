class Solution {
public:
    int maximumDifference(vector<int>& a) 
    {
        int n=a.size();
        stack<int> s;
        int ans=-1;
        s.push(a[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            if(s.size()!=0)
            {
                if(s.top() > a[i])
                {
                    ans=max(ans,(s.top()-a[i]));
                }
                else
                {
                    s.pop();
                    s.push(a[i]);
                }
            }
        }
        return ans;
    }
};