class Solution {
public:
    int tupleSameProduct(vector<int>& a) 
    {
        unordered_map<int,vector<int>> mp;
        sort(a.begin(),a.end());
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int prod=a[i]*a[j];
                mp[prod].push_back(a[i]);
                mp[prod].push_back(a[j]);
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int prod=a[i]*a[j];
                if(mp.find(prod)!=mp.end())
                {
                    vector<int> v=mp[prod];
                    int vsize=v.size();
                    // for(int x=0;x< vsize;x=x+2)
                    // {
                    //     if(v[x]!=a[i] and v[x]!=a[j] and v[x+1]!=a[i] and v[x+1]!=a[j])
                    //     {
                    //         // cout<<a[i]<<" "<<a[j]<<" "<<v[x]<<" "<<v[x+1]<<"\n";
                    //         ++count;
                    //     }
                    //     // else
                    //     //     break;
                    // }
                    count=count+(vsize/2)-1;
                }
            }
        }
        return count*4;
    }
};