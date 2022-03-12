class Solution {
public:
    int res;
    
    bool isPalindrome(string S)
    {
      for (int i = 0; i < S.length() / 2; i++) 
      {
        if (S[i] != S[S.length() - i - 1]) 
        {
            return false;
        }
    }
    return true;
    }
    
    void dfs(string &s,string &s1,string &s2,int n)
    {
        if(n==0)
        {
            if(isPalindrome(s1) and isPalindrome(s2))
            {
                int a=s1.size();
                int b=s2.size();
                res=max(res,(b*a));
            }
            return ;
        }    
        else
        {
            s1.push_back(s[n-1]); //inserted in s1
            dfs(s,s1,s2,n-1);
            s1.pop_back();
            s2.push_back(s[n-1]); //inserted in s2
            dfs(s,s1,s2,n-1);
            s2.pop_back();
            dfs(s,s1,s2,n-1);  // not in both
        }
    }
    
    int maxProduct(string s) 
    {
        res=0;
        string s1="",s2="";
        dfs(s,s1,s2,s.size());
        return res;
    }
};