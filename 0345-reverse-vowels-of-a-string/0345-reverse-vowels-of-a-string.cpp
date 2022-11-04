class Solution {
public:
    bool isVowel(char c)
    {
        return (c=='a' or c=='e' or c=='i' or c=='o' or c=='u' or c=='A' or c=='E' or c=='I' or c=='O' or c=='U' );
    }
    
    string reverseVowels(string s) {
       
        int i=0;
        int j=s.size()-1;
        
        while(i<j)
        {
            while( isVowel(s[i]) == false and i<s.size()-1)
            {
                ++i;
            }
            while( isVowel(s[j]) == false and j>0)
            {
                --j;
            }
            
            if(i<j) swap(s[i],s[j]);
            
            ++i;
            --j;
            
        }
        
        return s;
        
    }
};