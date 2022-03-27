class Solution {
public:
  
   int f(vector<int> &a)
   {
     int count=0;
     int n=a.size();
     for(int i=0;i<n;i++)
     {
       if(a[i]==1)
         ++count;
       else
         return count;
     }
     return count;
   }
    
  
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        priority_queue<pair<int,int>> pq;
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
            int ones=f(mat[i]);
            pq.push({ones,i});
            if(pq.size()>k)
              pq.pop();
        }
        vector<int> ans;
        while(pq.size()>0)
        {
            int weakIndex=pq.top().second;
            pq.pop();
            ans.push_back(weakIndex);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};