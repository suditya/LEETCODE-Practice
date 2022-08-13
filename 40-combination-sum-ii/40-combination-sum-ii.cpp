class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void f(vector<int>& a, int target , vector<int> &path, int i)
    {
        // cout<<i<<" ";
        if(target==0) { /*cout<<"  pushed  ";*/ ans.push_back(path); return ;}
        else if(i>=n) return ;
        else
        {
            if(a[i] > target ) return ;
            else
            {
                // cout<<i<<" ";
                path.push_back(a[i]);
                f(a, target-a[i], path , i+1);
                path.pop_back();
                int j=i;
                while(j<n and a[j]==a[i])
                {
                    ++j;
                }
                f(a, target , path , j);    
            }
        }
            
    }
    
    vector<vector<int>> combinationSum2(vector<int>& a, int target) 
    {
        sort(a.begin(),a.end());
        n=a.size();
        vector<int> path;
        f(a, target ,path, 0);   
        return ans;
    }
};