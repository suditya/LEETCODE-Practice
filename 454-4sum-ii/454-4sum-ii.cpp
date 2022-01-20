class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        unordered_map<int,int> mp;
        int n=nums1.size();
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<n;j++)
          {
              
              {
                  int sum=nums1[i]+nums2[j];
                  // cout<<nums1[i]<<" "<<nums2[j]<<" "<<nums3[k]<<"\n";
                  mp[sum]++;
              }
          }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=ans+mp[-(nums3[i]+nums4[j])];
            }
        }
        return ans;
    }
};