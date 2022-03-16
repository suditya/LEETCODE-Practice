// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string S,int x,int y)
    {
        // Iterate over the range [0, N/2]
        int z=(y-x)+1;
        int w=x+(z/2); //
        int c=0;
        for (int i = x; i < w; i++) {
            if (S[i] != S[y-c]) {
                // Return No
                return false;
            }
            ++c;
        }
        // Return "Yes"
        return true;
    }
    int b;
    // map<pair<int,int>,int> dp;
    int dp[1001][1001];
    int f(string &s,int i,int j)
    {
        if(i>=j) return 0;
        // else if(dp.find({i,j})!=dp.end())
        // {
        //     // cout<<"hey ";
        //     return dp[{i,j}];
        // }
        else if(dp[i][j]!=-1)
            return dp[i][j];
        else
        {
            ++b;
            // string si;
            // si=s.substr(i,(j-i+1));
            // for(int x=i;x<=j;x++)
            // si.push_back(s[x]);
            if(isPalindrome(s,i,j))
            {
                return 0;
            }
            int ans=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int temp=0;
                temp=f(s,i,k)+f(s,k+1,j)+1;
                ans=min(ans,temp);
            }
            // return dp[{i,j}]=ans;
            return dp[i][j]=ans;
        }
    }
    
    int palindromicPartition(string str)
    {
        int i=0;
        b=0;
        int j=str.size()-1;
        memset(dp, -1, sizeof(dp));
        int ans=f(str,0,j);
        // cout<<(j+1)<<" "<<b;
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends