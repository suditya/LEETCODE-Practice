// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    vector<vector<int>> ans;
    
    void f(vector<int>& a,vector<int> path,int i,int n)
    {
        if(n==i)
        ans.push_back(path);
        else
        {
            // cout<<n<<"\n";
            // for(auto i: path) cout<<i<<" ";
            // cout<<"\n";
            path.push_back(a[i]);
            f(a,path,i+1,n);
            path.pop_back();
            f(a,path,i+1,n);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& a)
    {
        vector<int> path;
        f(a,path,0,a.size());
        sort(ans.begin(),ans.end());
        return ans;
        //code here
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends