class Solution {
public:
    vector<string> s;
    
    void f(int i,int n,string path)
    {
        if(i>=n)
        {
            // cout<<path<<" ";
            s.push_back(path);
            return ;
        }
        else
        {
            if(i==0)
            {
                string x="a",y="b",z="c";
                f(i+1,n,x);
                f(i+1,n,y);
                f(i+1,n,z);
            }
            else
            {
                if(path[i-1]=='a')
                {
                    path.push_back('b');
                    f(i+1,n,path);
                    path.pop_back();
                    path.push_back('c');
                    f(i+1,n,path);  
                }
                else if(path[i-1]=='b')
                {
                    path.push_back('a');
                    f(i+1,n,path);
                    path.pop_back();
                    path.push_back('c');
                    f(i+1,n,path);
                }
                else
                {
                    path.push_back('a');
                    f(i+1,n,path);
                    path.pop_back();
                    path.push_back('b');
                    f(i+1,n,path);
                }
            }
        }
    }
    
    string getHappyString(int n, int k) 
    {
        string path;
        f(0,n,path);
        if(s.size() < k) return "";
        sort(s.begin(),s.end());
        return s[k-1]; 
    }
};