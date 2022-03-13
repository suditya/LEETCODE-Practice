class Solution {
public:
    bool isValid(string s) 
    {   int n=s.size();
        stack <int> p;
        for(int i=0;i<n;i++)
     {
        if( s[i]=='{' or s[i]== '(' or s[i]=='[' )
            p.push(s[i]);
        else
        {   
           {
            if(p.empty()==false)
            { char c=p.top();            
            if(c== '(' )
                if(s[i]!=')')
                    return false;
            if(c=='{' )
                if(s[i]!='}')
                    return false;
            if(c=='[')
                if(s[i]!=']')
                    return false;
            // if(p.empty() ==false)
            p.pop();
            }
            else
            {
                return false;
            }
           }
        }
    }
        if (p.empty())
            return true;
        else
            return false;
        
    }

};