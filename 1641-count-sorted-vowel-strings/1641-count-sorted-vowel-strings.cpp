class Solution {
public:
    vector<char> vowels;
    int ans;
    
    void f(int n,string &path,int i=1)
    {
        if(i==n) { ++ans; return ;}
        else
        {
            for(auto ch:vowels)
            {
                if(ch <= path[i-1])
                {
                    path.push_back(ch);
                    f(n,path,i+1);
                    path.pop_back();
                }
            }
        }
    }
    
    int countVowelStrings(int n) {
        if(n==1) return 5;
        vowels={'a','e','i','o','u'};
        ans=0;
        for(auto ch: vowels)
        {
            string path; path.push_back(ch);
            f(n,path,1);
        }
        return ans;
    }
};