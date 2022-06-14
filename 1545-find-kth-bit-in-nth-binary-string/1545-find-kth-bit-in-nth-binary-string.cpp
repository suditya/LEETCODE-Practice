class Solution {
public:
    string revert(string &prev)
    {
        for(int i=0;i<prev.size();i++)
        {
            if(prev[i]=='1')
                prev[i]='0';
            else
                prev[i]='1';
        }
        // cout<<prev<<" ";
        reverse(prev.begin(),prev.end());
        // cout<<"reversed "<<prev<<" ";
        return prev;
    }
    string f(int n)
    {
        if(n==1) return "0";
        else
        {
            string prev=f(n-1);
            string ans;
            ans=prev+"1"+revert(prev);
            return ans;
        }
    }
    
    char findKthBit(int n, int k) 
    {
        string s=f(n);
        cout<<s;
        return s[k-1];
    }
};