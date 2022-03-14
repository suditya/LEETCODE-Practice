class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) 
    {  
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                string s1=nums[i]+nums[j];
                string s2=nums[j]+nums[i];
                if(s1==target)
                    ++count;
                if(s2==target)
                    ++count;
            }
        }
        return count;
    }
};