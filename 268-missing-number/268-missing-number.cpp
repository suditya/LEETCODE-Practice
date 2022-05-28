class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n=nums.size();
        int totalSum=(n*(n+1))/2;
        int currSum=0;
        for(auto i:nums) currSum+=i;
        int missNum=totalSum-currSum;
        cout<<missNum;
        return missNum;
    }
};