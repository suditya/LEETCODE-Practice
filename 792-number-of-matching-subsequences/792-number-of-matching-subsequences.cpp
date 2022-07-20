class Solution {
public:
    
    unordered_map<string,bool> dp;
    
    bool f(string &s,string &t,int n,int m,int i,int j)
    {
        
        if(i==n) return true;
        else if(j==m) return false;
        else
        {
            // cout<<"hi";
            // cout<<i<<" "<<j<<"\n";
            if(s[i]==t[j])
            {
                return f(s,t,n,m,i+1,j+1);
            }
            else return f(s,t,n,m,i,j+1);
        }
    }
    
    
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        // string path;
        // n=s.size();
        // subsequences(s,0,path);
        int count=0;
        int m=s.size();
        for(auto word : words)
        {
            int n=word.size();
            if(dp.find(word)!=dp.end())
            {
                if(dp[word]==true) ++count;
            }
            else
            {
                dp[word]=f(word,s,n,m,0,0);
                if(dp[word]==true) ++count;
            }
        }
        return count;
    }
};