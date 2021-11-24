class Solution {
public:
    int missingNumber(vector<int>& a) 
    {
        long sum=0;
        long n=a.size();
        for(auto i:a)
        {
            sum+=i;
        }
        long expected_sum=(n*(n+1))/2;
        return int(expected_sum-sum);
        
    }
};