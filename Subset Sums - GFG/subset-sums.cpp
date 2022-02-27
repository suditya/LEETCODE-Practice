// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> ans;

    void dfs(vector<int> a, int n,int sum=0)
    {
        if(n<=0) return ;
        else
        {
            int temp=sum;
            sum=sum+a[n-1];
            ans.push_back(sum);
            dfs(a,n-1,sum);
            dfs(a,n-1,temp);
            return ;
        }
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        dfs(arr,N,0);
        ans.push_back(0);
        return ans;
        // Write Your Code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends