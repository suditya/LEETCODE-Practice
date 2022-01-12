class Solution {
public:
    vector<vector<int>> ans;
    vector<int> f( int n)
    {
        if(n==1) return {1};
        else
        {
            vector<int> v=f(n-1);
            ans.push_back(v);
            vector<int> p;
            p.push_back(1);
            for(int i=0;i<v.size()-1;i++)
            {
                p.push_back(v[i]+v[i+1]);
            }
            p.push_back(1);
            // ans.push_back(p);
            return p;
        }
        
           
    }
    vector<vector<int>> generate(int numRows) 
    {
        vector<int> temp= f(numRows);
        ans.push_back(temp);
        return ans;
    }
};