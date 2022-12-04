class Solution {
public:
    int minimumAverageDifference(vector<int>& a) 
    {
        long long sum=0;
        
        
        for(auto i:a)
            sum+=i;
        
        
        long long n=a.size();
        long long  lSum=0;
        int ansIndex=-1;
        long long min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            lSum+=a[i];
            long long left = round(lSum/(i+1));
            long long right;
            if(i< n-1)
            right = round ((sum-lSum)/(n-i-1));
            else right =0;
            
            
            if(abs(left-right) < min)
            {
                min = abs(left-right);
                ansIndex=i;
            }
        }
        
        return ansIndex;
    }
};