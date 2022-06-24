class Solution {
public:
    vector<int> ans;
    bool topoSort(int node,vector<int> adj[],vector<int>& vis,vector<int> &cycle)
    {
        if(cycle[node]==1) return false; //node exist in cycle
        else if(vis[node]==1) return true; //already visited but not in cycle
        else
        {
            vis[node]=1; //visiting the node
            cycle[node]=1; //putting the node in cycle
            for(auto i:adj[node])
            {
                // if(vis[i]==0)
                {
                    if(topoSort(i,adj,vis,cycle)==false)
                        return false;
                }
            }
            ans.push_back(node);
            cycle[node]=0;
            return true;
        }
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) 
    {
        vector<int> adj[numCourses+1];
        for(auto v:pre)
        {
            adj[v[0]].push_back(v[1]);
        }
        vector<int> vis(numCourses+1,0);
        
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]==0)
            {
                vector<int> cycle(numCourses+1,0);
                if(topoSort(i,adj,vis,cycle)==false)
                    return {};
            }   
        }
        return ans;
    }
};