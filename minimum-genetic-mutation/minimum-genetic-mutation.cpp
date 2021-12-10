class Solution {
public:
    unordered_map<string, vector<string>> mp;
    unordered_map<string, int> vis;
    unordered_map<string,int> dis;
    bool s=false, e=false;
    void bfs(string start, string end,vector<string> bank )
    {
        // int dis[1000];
        // for(int i=0;i<1000;i++)
        // {
        //     dis[i]=INT_MAX;
        // }
        queue<string> q;
       
        for(int i=0;i<bank.size();i++)
        {
            dis[bank[i]]=INT_MAX;
        }
        q.push(start) ;
        dis[start]=0;
        while(q.size()!=0)
        {
            string s=q.front() ;
            q.pop();
            vis[s]=1;
            vector<string> v=mp[s];
            for(int i=0;i<v.size();i++)
            {
                if(vis[v[i]]==0)
                {
                    q.push(v[i]);
                    dis[v[i]]=min(dis[v[i]],dis[s])+1;
                }
            }
        }
        return ;
    }
    
    bool similar(string s, string t)
    {
        int error=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=t[i])
                ++error;
            if(error > 1 )
                return false;
        }
        return true;
    }
    
    int minMutation(string start, string end, vector<string>& bank) 
    {
        
        for(int i=0;i< bank.size();i++)
        {
            if(bank[i]==start) s=true;
            if(bank[i]==end) e=true;
            for(int j=0;j<bank.size();j++)
            {
                if(i!=j)
                {
                    if(similar(bank[i],bank[j]))
                    {
                        mp[bank[i]].push_back(bank[j]);
                        mp[bank[j]].push_back(bank[i]);
                    }
                }
            }
        }     
        if(e== false) //if end doesnt exist in bank 
            return -1;
        if(s== false) //if start is not in bank  
        {
            for(int i=0;i<bank.size();i++)
            {
                if(similar(start,bank[i]))
                {
                    mp[bank[i]].push_back(start);
                    mp[start].push_back(bank[i]);
                }
            }
        }
        // vector<string> v=mp[start];
        // cout<<start<<" ";
        // for(int i=0;i<v.size();i++)
        // {
        //     cout<<v[i]<<" ";
        // }
        // cout<<"\n";
         
        for(int i=0;i<bank.size();i++)
        {
            vis[bank[i]]=0;
        }
        // if(s==false)
            
        

        bfs(start,end,bank);
        cout<<dis[end]<<" ";
        if(dis[end] >100)
            return -1;
        return dis[end];
        
    }
};