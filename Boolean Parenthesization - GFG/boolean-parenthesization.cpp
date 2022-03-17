// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int dp[250][250];
    unordered_map<string,int> dp;
    int mod=1003;
    int f(string &s,int i,int j,int isTrue)
    {
        if(i>j) return 0;
        else if(i==j) 
        {
            if(isTrue==1)
            return s[i]=='T';
            else
            return s[i]=='F';
        }
        // else if(dp.find()!=dp.end())
        // {
        //     // cout<<"hey1";
        //     return dp[{i,j,isTrue}];
        // }
        else
        {
            // cout<<"hey2";
            // string x=i+" "+j+" "+isTrue;
            string x;
            string ix=to_string(i);
            
            // x=to_string(i);
            // x.push_back(" ");
            string jx=to_string(j),isTruex=to_string(isTrue);
            // jx
            // isTruex=;
            x=x+ix+" "+jx+" "+isTruex;
            // cout<<x<<"\n";
            if(dp.find(x)!=dp.end())
            {
                // cout<<"! ";
                return dp[x];
                
            }
            int ans=0;
            for(int k=i;k<j;k=k+2)
            {
                int lf=f(s,i,k,0);
                int lt=f(s,i,k,1);
                int rf=f(s,k+2,j,0);
                int rt=f(s,k+2,j,1);
                
                if(s[k+1]=='^')
                {
                    // if(isTrue==1)
                    // {
                    //     count+= lf*rt + lt*rf;
                    //     count=count%(1003);
                    // }
                    // else
                    // {
                    //     count+= lf*rf+ lt*rt;
                    //     count=count%(1003);
                    // }
                     if(isTrue == 1)
           ans = ((ans % mod) + (lt*rf)% mod + (lf*rt))% mod;
           else
            ans = ((ans % mod) + (lt*rt)% mod + (lf*rf))% mod;
                }
                else if(s[k+1]=='|')
                {
                    // if(isTrue==1)
                    // {
                    //     count+=( (lf*rt) + (lt*rf) + (lt*rt));
                    //     count=count%(1003);
                    // }
                    // else
                    // {
                    //     count+= lf*rf;
                    //     count=count%(1003);
                    // }
                    if(isTrue == 1)
            ans = ((ans % mod) + (lt*rt)% mod + (lf*rt)% mod + (lt *rf))% mod;
           else
            ans = ((ans % mod) + (lf*rf));
                }
                else // when operator if '&'
                {
                //   if(isTrue==1)
                //     {
                //         count+= lt*rt;
                //         count=count%(1003);
                //     }
                //     else
                //     {
                //         count+= lf*rf+lf*rt+rt*lf;
                //         count=count%(1003);
                //     } 
                if(isTrue == 1)
               ans = ((ans % mod) + (lt*rt)%mod) % mod;
               else
               ans = ((ans % mod) + (lt*rf)% mod + (lf * rt)% mod + (lf * rf))% mod;
                }
                
            }
            // count=count%(1003);
            ans=ans% mod;
            return dp[x]=ans;  
        }
    }
    
    int countWays(int N, string S)
    {
        return f(S,0,N-1,1);
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends