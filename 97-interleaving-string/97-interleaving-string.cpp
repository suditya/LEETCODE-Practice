class Solution {
public:
    int n;
    int m;
    map<pair<int,int>,int> dp;
    bool f(string s1,string s2,string s3,int x,int y,int z)
    {
        if(z>= s3.size())
            return true;
        else if(dp.find({x,y})!=dp.end())
            return dp[{x,y}];
        else
        {
            if(x<n and s3[z]==s1[x] and y<m and s3[z]==s2[y])
            {
                return dp[{x,y}]=(f(s1,s2,s3,x+1,y,z+1)|f(s1,s2,s3,x,y+1,z+1));
            }
            else if(x<n and s3[z]==s1[x])
            {
                return dp[{x,y}]=f(s1,s2,s3,x+1,y,z+1);
            }
            else if(y<m and s3[z]==s2[y])
            {
                return dp[{x,y}]=f(s1,s2,s3,x,y+1,z+1);
            }
            else
                return false;
        }
    }
    
    bool isInterleave(string s1, string s2, string s3) 
    {
        if(s3.size()!= (s1.size()+s2.size())) return false;
        // int x=0,y=0,z=0;
        n=s1.size();
        m=s2.size();
        // int p=s3.size();
        return f(s1,s2,s3,0,0,0);
        
    }
};