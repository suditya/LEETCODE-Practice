// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int shouldPunish (int roll[], int marks[], int n, double avg)
    {
        int swaps=0;
        int totalMark=0;
        for(int i=0;i<n;i++)
        {
           
            for(int j=0;j<n-1-i;j++)
            {
                if(roll[j]>roll[j+1])
                {
                    ++swaps;
                    swap(roll[j],roll[j+1]);
                }
            }
        }
        for(int i=0;i<n;i++)
             totalMark+=marks[i];
        // cout<<"\n";
        // cout<<swaps<<" ";
        // cout<<totalMark<<" ";
        double afterAvg=((totalMark-swaps)/n );
        // cout<<afterAvg;
        if(afterAvg < avg) return 0;
        return 1;
        // your code here
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		double avg; cin >> avg;

		int roll[n];
		int marks[n];

		for (int i = 0; i < n; ++i)
			cin >> roll[i];
		for (int i = 0; i < n; ++i)
			cin >> marks[i];
        Solution ob;
		cout << ob.shouldPunish (roll, marks, n, avg) << endl;
	}
}
  // } Driver Code Ends