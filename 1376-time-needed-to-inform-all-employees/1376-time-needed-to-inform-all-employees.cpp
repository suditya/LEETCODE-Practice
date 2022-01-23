class Solution {
public:
    
    unordered_map<int,vector<int>> childs;
    vector<int> inform ;
    
    int f(int start)
        {
            vector<int> children= childs[start];
            if(children.size()  == 0)
                return 0;
            else
            {
                int ans=0;
                for(int i=0;i<children.size();i++)
                {
                   ans=max(ans,f(children[i])); 
                }
                return ans+inform[start];
            }
        }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        if(n==0) return 0;
        else
        {
            int root=-1;
            
            inform = informTime;
            
            for(int i=0;i<n;i++)
            {
                if(manager[i]!=-1)
                {
                    childs[manager[i]].push_back(i);
                }
                else
                {
                    root=i;
                }
            }
            
            int ans=f(root);
            return ans;
            
        }  
        
    }
};