class Solution {
public:
    int dp[501][502];
    bool f(vector<int>& a,int start,int end,int A,int B,int turn)
    {
        if(start > end) 
        {
            return (A>B);
        }
        else if(dp[start][end]!=-1)
            return dp[start][end];
        else
        {
            if((turn&1)==0) //if alice turn 
            {
                return dp[start][end]=(f(a,start+1,end,A+a[start],B,turn+1) or f(a,start,end-1,A+a[end],B,turn+1));
            }
            else
            {
                return dp[start][end]=(f(a,start+1,end,A,B+a[start],turn+1) or f(a,start,end-1,A,B+a[end],turn+1));
            }
        }
    }
    
    bool stoneGame(vector<int>& piles) 
    {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        return f(piles,0,n-1,0,0,0);   
    }
};