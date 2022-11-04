class Solution {
public:
    bool isVowel(char c)
    {
        return (c=='a' or c=='e' or c=='i' or c=='o' or c=='u' or c=='A' or c=='E' or c=='I' or c=='O' or c=='U' );
    }
    
    string reverseVowels(string s) {
        stack<char> st;
        for(auto& c:s)
        {
            if( isVowel(c) == true)
            {
                st.push(c);
                c='*';
            }
        }
        for(auto& c:s)
        {
            if( c=='*')
            {
                char x = st.top(); st.pop();
                c=x;
            }
        }
        
        return s;
    }
};