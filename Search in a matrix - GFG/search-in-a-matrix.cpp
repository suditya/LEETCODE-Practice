// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int n, int m, int x)
	{
	    int i=0;
	    int j=m-1;
	    while(i>=0 and i<n and j>=0 and j<m)
	    {
	        if(mat[i][j]==x)
	        {
	            return 1;
	        }
	        else if(mat[i][j]>x)
	        {
	            --j;
	        }
	        else
	        {
	            ++i;
	        }
	    }
	    return 0;
	    // your code here
	}
};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}  // } Driver Code Ends