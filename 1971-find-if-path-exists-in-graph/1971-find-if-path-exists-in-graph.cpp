class Solution {
public:
    int parent[200005];
    int rank[200005];
    void unionn(int x,int y)
    {
        int px=findParent(x);
        int py=findParent(y);
        if(px==py) return ;
        if(rank[px]==rank[py])
        {
            if(px < py)
            {
                rank[px]++;
                parent[py]=parent[px];
            }
            else
            {
                rank[py]++;
                parent[px]=parent[py];
            }
        }
        else if(rank[px] > rank[py])
        {
            parent[py]=px;
        }
        else 
        {
            parent[px]=py;
        }
    }
    
    int findParent(int x)
    {
        if(parent[x]==x) return x;
        else
        {
            return parent[x]=findParent(parent[x]);
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        memset(rank,0,n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        for(auto v: edges)
        {
            unionn(v[0],v[1]);
        }
        
        return (findParent(source)==findParent(destination));
    }
};