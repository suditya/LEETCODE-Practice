class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<pair<char,int>> st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(c=='(')
                st.push({'(',i});
            else if(c==')')
            {
                if(st.size()>0 and st.top().first=='(')
                    st.pop();
                else
                    st.push({')',i});                    
            }
            else
            {
                ;
            }
        }
        // map<int,int> mp;
        // for(auto x : st)
        // {
        //     mp[x.second]=1;
        // }
        while(st.size()>0)
        {
            int index= st.top().second;
            // mp[index]=1;
            s[index]='!';
            st.pop();
        }
        string newString;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='!')
            {
                ;
            }
            else
            {
                newString.push_back(s[i]);
            }
        }
        return newString;
    }
};