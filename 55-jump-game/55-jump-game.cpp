class Solution {
public:
    // vector<int> dp; 
//     int dp[100004];
//     int f(vector<int> a,int i)
//     {
        
//         if(i>=a.size()-1)
//             return dp[i]=1;
//         if(i+a[i]>= a.size()-1)
//             return dp[i]=1;
//         if(dp[i]!=-1) return dp[i];
//         else if(i+a[i] < a.size()-1)
//         {
            
//             for(int j=i+1;j<=i+a[i];j++)
//             {
//                 cout<<i<<" "<<j<<"\n";
//                 if(f(a,j))
//                     return dp[i]=1;
//             }
//             return dp[i]=0;
//         }
//         else return dp[i]=1;
//     }
//     int f(vector<int> a, int i)
//     {
        
//     }
    
    bool canJump(vector<int>& a) 
    {
//         memset(dp,-1,sizeof(dp));
//         return f(nums,0);
        
        int n=a.size();
        int dp[n];
        memset(dp,-1,sizeof(dp));
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            if(i+a[i] >=n-1)
                dp[i]=1;
            else
            {
                for(int j=i+1;j<=i+a[i];j++)
                {
                    if(dp[j]==1)
                    {
                        dp[i]=1;
                        break;
                    } 
                   
                }
                if(dp[i]==-1)
                    dp[i]=0;
            }
            
        }
        if(dp[0]==1) return true;
        else return false;
    }
};