class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> inDegree(n+1,0);
        vector<int> outDegree(n+1,0);
        for(auto v:trust)
        {
            inDegree[v[1]]++;
            outDegree[v[0]]++;
        }
        for(int i=1;i<=n;i++)
        {
            // cout<<i<<" "<<indegree[i]<<"\n";
            if(inDegree[i]==n-1 and outDegree[i]==0) return i;
        }
        return -1;
    }
};