//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    // vector<string> perm;
    
    // void permutate(string num, int i , int n)
    // {
    //     if(i==n-1) 
    //     {
    //         perm.push_back(num);
    //         return ;
    //     }
    //     else
    //     {
    //         for(int j=i;j<n;j++)
    //         {
    //             swap(num[j],num[i]);
    //             permutate(num, i+1,n);
    //             swap(num[j],num[i]);
    //         }
    //         return ;
    //     }
    // }
    
    string kthPermutation(int n, int k)
    {
        string num = "";
        for(int i=1;i<=n;i++)
        {
            num += to_string(i);
            // cout<<num<<"\n";
        }
        
        // permutate(num,0,n);
        // sort(perm.begin(),perm.end());
        // return perm[k-1];
        // cout<<num<<"\n";
        for(int i=0;i<k-1;i++)
        {
            next_permutation(num.begin(),num.end());
            // cout<<num<<"\n";
        }
        
        return num;
        // code here
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends