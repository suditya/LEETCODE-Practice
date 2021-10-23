class Solution {
public:
    int countSubstrings(string s) 
    {
        int count=1;
        int n=s.size();
        for(int i=0;i<n-1;i++)
        {
            int l1,r1;
            l1=r1=i;
            while(l1>=0 and r1<n)
            {
                if(s[l1]==s[r1])
                {
                    ++count;
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
                        ++count;
                    }
                    else
                        break;
                    --l2,++r2;
                }
            }
        }
        return count;
        
    }
};