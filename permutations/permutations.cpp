class Solution {
public:
    vector<vector<int>> f(vector<int>& a,int n)
    {
        if(n==1)
        {
            return {{a[n-1]}};
            
        }
        else
        {
            vector<vector<int>> v=f(a,n-1);
            //(1,2) (2,1)
            int x= a[n-1];
            vector<vector<int>> ans;
            for(int i=0;i<v.size();i++)
            {
                vector<int> vi= v[i];
                vector<int> vj= v[i];
                vi.push_back(x);
                ans.push_back(vi); //pushing at the end;
                vj.insert(vj.begin(), x); 
                ans.push_back(vj); //pushing at the front
            }
            for(int i=0;i<v.size();i++)
            {
                vector<int> vi=v[i];
                for(int j=1;j<n-1;j++)
                {
                    vector<int> vx=vi;
                    vx.insert(vx.begin()+j,x);
                    ans.push_back(vx);
                }
            }
            
            
            
            return ans;
            
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        return f(nums,nums.size());
        
    }
};