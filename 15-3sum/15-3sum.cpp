class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) 
    {
        set<vector<int>> ans;
        int n=a.size();
        if(n<3) return {};
        sort(a.begin(),a.end());
        // for(auto x:a) cout<<x<<" ";
        // cout<<"\n";
        for(int i=0;i<n;i++)
        {
            int z=a[i];
            int x=i+1;
            int y=n-1;
            z=(-1)*z;
            // cout<<z<<"\n";
            while(x<y)
            {
                
                if( x==i )
                {
                    // while(x!=i)
                    ++x;
                }
                if(y==i)
                {
                    --y;  
                }
                if(x>=y) break;
                // cout<<a[x]<<" "<<a[y]<<" "<<(-z)<<"\n";
                if(a[x]+a[y] == z)
                {
                    // cout<<"hi upar waala\n";
                    vector<int> v={a[x],a[y],((-1)*z)};
                    sort(v.begin(),v.end());
                    ans.insert(v);
                    ++x;
                    --y;
                }
                else if(a[x]+a[y] < z)
                {
                    ++x;
                }
                else
                {
                    --y;
                }
            }
            
        }
        vector<vector<int>> real;
        for(auto x: ans)
        {
            real.push_back(x);
        }
        return real;
    }
};