class Solution {
public:
    int count;
    
    void dfs(vector<int>& a,int n,vector<int> path,int d=0)
    {
        if(n<0) return ;
        else
        {
            if(path.size()==0)
            {
                path.push_back(a[n]);
                dfs(a,n-1,path,d);
                path.pop_back();
                dfs(a,n-1,path,d);
            }
            else if(path.size()==1)
            {
                path.push_back(a[n]);
                int dif=path[path.size()-2]-a[n];
                dfs(a,n-1,path,dif);
            }
//             else if(path.size()==2)
//             {
                
//             }
            else
            {
                int dif=path[path.size()-1]-a[n];
                if(dif==d)
                {
                    path.push_back(a[n]);
                    dfs(a,n-1,path,d);
                    if(path.size()>=3)
                    {
                        // cout<<d<<" ";
                        // for(auto x:path) cout<<x;
                        // cout<<"\n";
                        // cout<<"hey";
                        ++count;
                    }
                }
                
            }
        }
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        vector<int> path;
        dfs(nums,nums.size()-1,path,0);
        return count;
    }
};