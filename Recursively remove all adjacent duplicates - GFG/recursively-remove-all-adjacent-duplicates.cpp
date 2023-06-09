//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rremove(string s){
        string ans;
        // ans.push_back(s[0]);
        bool duplicateExist = true;
        while(duplicateExist)
        {
            duplicateExist = false;
            for(int i=0;i<s.size();i++)
            {
                if(i==0)
                {
                    if(s[i+1]!=s[i])
                    {
                        ans.push_back(s[i]);
                    }
                    else
                    duplicateExist = true;
                }
                else if(i==s.size()-1)
                {
                    if(s[i-1]!=s[i])
                    {
                        ans.push_back(s[i]);
                    }
                    else
                    duplicateExist = true;
                }
                else
                {
                    if(s[i]!=s[i-1] and s[i]!=s[i+1]) ans.push_back(s[i]);
                    else duplicateExist = true;
                }
                
            }
            s = ans;
            ans = "";
        }
        return s;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends