class Solution {
public:
    unordered_map<string,int> dis;
    unordered_map<string,int> vis;
    int b=0,e=0;
    map<string, vector<string>> connection;
    int ladderLength(string begin, string end, vector<string>& word) 
    {
       
        int n=word.size();
        // vector<string> connection[5009];
        
       
        for(int i=0;i<n;i++)
        {
            if(word[i]==begin) ++b;
            if(word[i]==end) ++e;
            for(int j=i+1;j<n;j++)
            {
                if(similiar(word[i],word[j]))
                {
                    // connection["suditya"].push_back("gupta");
                    string x=word[i];
                    string y=word[j];
                    connection[x].push_back(y);
                    connection[y].push_back(x);                
                }
            }
        }
        
        if(e==0) return 0; //no sequence exist
        if(b==0)  //if begin is not in sequence.
        {  
          for(int i=0;i<n;i++)
            {
                if( similiar(begin,word[i]) ==true)
                {
                    connection[begin].push_back(word[i]);
                    connection[word[i]].push_back(begin);                
                }
            }   
        }
      
        // for(int i=0;i<bank.size();i++)
        // {
        //     vis[bank[i]]=0;
        // }
        
            vis[begin]=0;
        for(int i=0;i< word.size();i++)
        {
            vis[word[i]]=0;
        }
        bfs(begin,end,word);
        // cout<<dis[end]<<" ";
        if(dis[end] >=10000)
            return 0;
        // if(b==1)
        // return dis[end]+1;
        // if(b==0)
        // {
        //     cout<<"  hi1";
        //     return dis[end];
        // } 
        
         cout<<begin<<": ";
         vector<string> a=connection[begin];
            for(int j=0;j<a.size();j++)
            {
                cout<<a[j]<<" ";
            }
            cout<<"\n";
        for(int i=0;i<n;i++)
        {
            cout<<word[i]<<": ";
            vector<string> s=connection[word[i]];
            for(int j=0;j<s.size();j++)
            {
                cout<<s[j]<<" ";
            }
            cout<<"\n";
        }
        
        cout<<"\n";
        // if(b==0)
        //     cout<<begin<<" "<<dis[begin]<<"\n";
        // for(int i=0;i<word.size();i++)
        // {
        //     cout<<word[i]<<" "<<dis[word[i]]<<"\n";
        // }
        return dis[end];
    }
    bool similiar(string a , string b)
    {
        int n=a.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i]) ++ans;
            if(ans>1) return false;
        }
        return true;
    }
    
    void bfs(string start, string end,vector<string>& bank )
    {   
        queue<string> q;
        for(int i=0;i<bank.size();i++)
        {
            dis[bank[i]]=10000;
        }
        dis[start]=10000;
        q.push(start) ;
        dis[start]=1;
        while(q.size()!=0)
        {
            string s=q.front() ;
            q.pop();
            vis[s]=1;
            vector<string> v=connection[s];
            for(int i=0;i<v.size();i++)
            {
                if(vis[v[i]]==0)
                {
                    q.push(v[i]);
                    vis[v[i]]=1;
                    dis[v[i]]=min(dis[v[i]],dis[s])+1;
                    cout<<v[i]<<" "<<dis[v[i]]<<"\n";
                    
                }
            }
        }
        return ;
    }
    
     
    };
