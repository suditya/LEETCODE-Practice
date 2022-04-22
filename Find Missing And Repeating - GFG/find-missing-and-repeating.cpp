// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *a, int n) 
    {
        int *b= new int[2];
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
        {
            freq[a[i]]++;
            if(freq[a[i]]==2)
            {
                b[0]=a[i];
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(freq[i]==0)
            {
                // cout<<"gotcha";
                b[1]=i;
                break;
            }
        }
        return b;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends