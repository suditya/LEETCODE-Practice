class Solution {
public:
    vector<vector<int>> generate(int n) 
    {
        if(n<=1)
            return {{1}};
        if(n==2)
            return {{1},{1,1}};
        else
        {
            // cout<<"hi1";
            vector<vector<int>> a=generate(n-1);
            // cout<<"hi2";
            
            vector<int> ans;
            // cout<<"hi2";
            
            ans.push_back(1);
            
            vector<int> last=a[a.size()-1];
            cout<<"hi2";
            
            int l=last.size();
            for(int i=0;i<(l-1);i++)
            {
                ans.push_back(last[i]+last[i+1]);
            }
            ans.push_back(1);
            a.push_back(ans);
            return a;
        }
            
    }
};