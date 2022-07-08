// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int a[],long long int n, long long int k) 
 {
     queue<pair<long long int ,long long int >> q;
     long long int i=0,j=0;
     vector<long long int> ans;
     while(j<n)
     {
         if(j-i+1 < k)
         {
             if(a[j] < 0)
             {
                 q.push({j,a[j]});
             }
             ++j;
         }
         else 
         {
            if(j-i +1 ==k)
            {
                if(a[j]<0)
                {
                    q.push({j,a[j]});
                }
                if(q.size()>0)
                {
                    ans.push_back(q.front().second);
                }
                else
                {
                    ans.push_back(0);
                }
                
                if(q.size() > 0)
                {
                    if(q.front().first==i)
                    {
                        q.pop();
                    }
                }
                ++i,++j;
            }
         }
     }
     return ans;
 }