// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n)
    {
        
        // stack<int> s;
        int gtr[n];
        // s.push(a[n-1]);
        // gtr[n-1]=-1;
        vector<int> ans;
        ans.push_back(a[n-1]);
        int currMax=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]  >= currMax)
            {
                ans.push_back(a[i]);
                currMax=max(currMax,a[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        // Code here
        
    }
};

// { Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
  // } Driver Code Ends