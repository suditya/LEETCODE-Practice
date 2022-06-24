class Solution {
public:
    bool isValid(string s) {
    stack<char> st;
    for(char c : s){
        if(c == '('){
            st.push(c);
        }else{
            if(st.empty()) return false;
            if(c == ')' && st.top() != '(') return false;
            st.pop();
        }
    }
    return st.empty();
    }
    
    vector<string> para;
    
    void generate(int open,int close,string path)
    {
        if(open==0 and close==0)
        {
            if(path[0]!=')' and path[path.size()-1]!='(')
            para.push_back(path);
            return ;
        }
        else
        {
            if(path.size()==0 or (open==close))
            {
                path.push_back('(');
                generate(open-1,close,path);
            }
            else if(open>0 and close>0)
            {
                path.push_back('(');
                generate(open-1,close,path);
                path.pop_back();
                path.push_back(')');
                generate(open,close-1,path);
            }
            else
            {
                if(open>0)
                {
                    for(int i=0;i<open;i++)
                    path.push_back('(');
                    generate(0,close,path);
                }
                else
                {
                    for(int i=0;i<close;i++)
                    path.push_back(')');
                    generate(open,0,path);
                }
            }
        }
    }
    
    vector<string> generateParenthesis(int n) 
    {
        string path;
        generate(n,n,path);
        vector<string> ans;
        for(auto s:para)
        {
            if(isValid(s)==true)
                ans.push_back(s);
        }
        return ans;
    }
};