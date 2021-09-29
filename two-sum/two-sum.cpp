class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) 
    {
       vector<int> ans;
       map<int,int> mp;
       int  n=a.size();
       for(int i=0;i<n;i++)
       {
           mp[a[i]]=i+1;
        //    cout<<mp[a[i]]<<" ";
       }
       for(int i=0;i<n;i++)
       {
        //   
           {
               if(mp[target-a[i]]!=0) //means exist 
               {
                   
                   if(mp[target-a[i]] > (i+1))
                   {
                       cout<<"hello";
                       ans.push_back(i);
                       ans.push_back(mp[target-a[i]]-1);
                   }
               }
           }
       }
       return ans;

     
    }
};