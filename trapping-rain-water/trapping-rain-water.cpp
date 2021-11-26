class Solution {
public:
    int trap(vector<int>& h) 
    {
        int n=h.size();
        int l[n];
        l[0]=-1;
        stack<int> s;
        s.push(h[0]);
        for(int i=1;i<n;i++)
        {
            while(s.size()!=0)
            {
                if(s.top()<=h[i])
                {
                    s.pop();
                }
                else
                {
                    l[i]=s.top();
                    break;
                }
            }
            if(s.size()==0)
            {
                s.push(h[i]);
                l[i]=-1;    
            }
        }
        // s.empty();
        stack<int> st;
        int r[n];
        r[n-1]=-1;
        st.push(h[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            while(st.size()!=0)
            {
                if(st.top()<=h[i])
                {
                    st.pop();
                }
                else
                {
                    r[i]=st.top();
                    break;
                }
            }
            if(st.size()==0)
            {
                st.push(h[i]);
                r[i]=-1;    
            }
        }
        // for(int i=0;i<n;i++) cout<<r[i]<<" ";
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(l[i]!=-1 and r[i]!=-1)
            {
                int x=min(l[i],r[i]);
                ans=ans+(x-h[i]);
            }
        }
        
        return ans;
    }
};