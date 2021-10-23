class Solution {
public:
    string longestPalindrome(string s) 
    {
        int ans=INT_MIN;
        int n=s.size();
        int l=0,r=0;
        for(int i=0;i<n-1;i++)
        {
            int l1,r1;
            l1=r1=i;
            while(l1>=0 and r1<n)
            {
                if(s[l1]==s[r1])
                {
                    // ++count;
                    if((r1-l1) > ans)
                    {
                        ans=(r1-l1);
                        l=l1;
                        r=r1;
                    }
                }
                else
                    break;
                --l1,++r1;
            }
            
            
            if(s[i]==s[i+1])
            {
                int l2,r2;
                l2=i, r2=i+1 ;
                while(l2>=0 and r2<n)
                {
                    if(s[l2]==s[r2])
                    {
                         if((r2-l2) > ans)
                        {
                            ans=(r2-l2);
                            l=l2;
                            r=r2;
                        }
                    }
                    else
                        break;
                    --l2,++r2;
                }
            }
        }
        string max_string="";
        for(int i=l;i<=r;i++)
        {
            max_string+=s[i];
        }
        
        return max_string;
        
    }
};