// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    int dp[100005];
    
    bool f(int a[],int i,int n)
    {
        if(i>=n-1) return true;
        else if(dp[i]!=-1) return dp[i];
        else
        {
            // cout<<i<<" ";
            for(int x=1;x<=a[i];x++)
            {
                if(f(a,i+x,n)==true)
                return dp[i]=true;
            }
            return dp[i]=false;
        }
    }
  
    int canReach(int a[], int n) {
        // code here
        memset(dp,-1,sizeof(dp));
        return f(a,0,n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends