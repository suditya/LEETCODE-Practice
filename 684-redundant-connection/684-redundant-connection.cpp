class Solution {
public:
    int parent[1005];
    bool found_the_answer;
    vector<int> ans;
    
    int find_parent(int x)
    {
        if(parent[x]==x) return x;
        else
            return find_parent(parent[x]);
    }
    
    void do_union(int u,int v)
    {
        int pu,pv;
        pu=find_parent(u);
        pv=find_parent(v);
        if(pu==pv)
        {
            ans={u,v};
            found_the_answer=true;
        }
        else
        {
            if(pu < pv)
                parent[pv]=pu;
            else
                parent[pu]=pv;
        }
    }
  
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n=edges.size();
        for(int i=0;i<n;i++)
            parent[i]=i;
        found_the_answer=false;
        
        for(int i=0;i<n;i++)
        {
            do_union(edges[i][0],edges[i][1]);
            if(found_the_answer == true)
             return ans; 
        }
        return {};
    }
};