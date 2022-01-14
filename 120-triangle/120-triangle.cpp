class Solution {
public:
    int n;
    int dp[205][207];
    int f(int i, int index,vector<vector<int>>& t)
    {
        if(dp[i][index]!=-1) return dp[i][index];
        if(index >= t[i].size() ) return INT_MAX;
        
        else if(i==n-1)
            return dp[i][index]=t[n-1][index];
        else
        {
            
            return dp[i][index]=(t[i][index]+min(f(i+1,index,t),f(i+1,index+1,t)));
        }
    }
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        cout<<"\n";
        for(int i=0;i<205;i++)
        {
            for(int j=0;j<207;j++)
                dp[i][j]=-1;
        }
        n=triangle.size();
        
        return f(0,0,triangle);
    }
};