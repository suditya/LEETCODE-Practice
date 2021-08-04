class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) 
    {
        vector<int> pf;
        int n=arr.size();
        cout<<"n"<<n;
        pf.push_back(0);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            // sum=sum+arr[i];
            pf.push_back(pf[i]+arr[i]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+2;j<=n;j=j+2)
            {
                sum=sum+(pf[j]-pf[i-1]);
            }
        }
        
        sum=sum+pf[n];
        cout<<sum;
        // if(n&1==1)
        //     sum=sum+pf[n];
        return sum;
        
        
    }
};