class Solution {
public:
    string f(string &s,string &t)
    {
        int n=s.size();
        int m=t.size();
        int lcs[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 or j==0)
                    lcs[i][j]=0;
                else if(s[i-1]==t[j-1])
                    lcs[i][j]=lcs[i-1][j-1]+1;
                else
                {
                    lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
                }
            }
        }
        // cout<<"hi1";
        int row=n;
        int col=m;
        string res;
        while(row>0 and col>0)
        {
            if(s[row-1]==t[col-1]) //both are equal
            {
                res.push_back(s[row-1]);
                --row;
                --col;
            }
            else
            {
                if(lcs[row-1][col]>lcs[row][col-1])
                {
                    res.push_back(s[row-1]);
                    --row;
                }
                else
                {
                    res.push_back(t[col-1]);
                    --col;
                }
            }
        }
        // cout<<"hey1";
        while(row > 0)
        {
            res.push_back(s[row-1]);
            --row;
        }
        while(col > 0)
        {
            res.push_back(t[col-1]);
            --col;
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
    
    
    string shortestCommonSupersequence(string str1, string str2) 
    {
        return f(str1,str2);   
    }
};