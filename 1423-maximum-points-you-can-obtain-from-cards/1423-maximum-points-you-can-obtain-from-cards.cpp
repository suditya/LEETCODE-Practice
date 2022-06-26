class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        //greedy approach should work i guess
        //i was wrong it was sliding window
        
        int sum=0;
        int minSum=0;
        
        for(auto i:cardPoints)
            sum+=i;
        // cout<<sum<<" ";
        int n=cardPoints.size();
        for(int i=0;i<(n-k);i++)
            minSum+=cardPoints[i];
        // cout<<minSum<<" ";
        int ans=minSum;
        
        int left=0;
        for(int i=(n-k);i<n;i++)
        {
            minSum=minSum+cardPoints[i]-cardPoints[left];
            // cout<<minSum<<" ";
            // if(minSum<)
            ans=min(minSum,ans);
            ++left;
        }
        return sum-ans ;
    }
};