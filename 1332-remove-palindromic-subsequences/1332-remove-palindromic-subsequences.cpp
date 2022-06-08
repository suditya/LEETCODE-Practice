class Solution {
public:
    
    bool isPalindrome(string s)
    {
        int n=s.size();
        for(int i=0;i<=n/2;i++)
        {
            if(s[i]!=s[n-1-i])
                return false;
        }
        return true;
    }
    
    int removePalindromeSub(string s) 
    {
        if(isPalindrome(s)==true) return 1;
        else
        {
          return 2;   
        }
    }
};