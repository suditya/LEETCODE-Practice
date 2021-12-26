class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
    {unordered_set<string> ss(supplies.begin(),supplies.end());
        bool f=true;
        int n=recipes.size();
        vector<int> vis(n,false);
        vector<string> res;
        while(f){
            f=false;
            for(int i=0;i<n;i++){
                if(vis[i]) continue;
                bool t=true;
                for(string &s:ingredients[i]){
                    if(ss.find(s)==ss.end()){
                        t=false;
                        break;
                    }
                }
                if(t){
                    f=true;
                    ss.insert(recipes[i]);
                    vis[i]=true;
                    res.push_back(recipes[i]);
                }
            }
        }
        return res;
        
    }
};