// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    
    bool isAnagram(map<char,int> &ang, map<char,int> &mp)
    {
        for(auto i: mp)
        {
            // if(ang.find(i.first)!=ang.end())
            {
                if(mp[i.first]!=ang[i.first])
                return false;
            }
            // else return false;
        }
        return true;
    }
    
	int search(string pat, string txt) 
	{
	   int count=0;
	   int i=0,j=0,n=txt.size(),k=pat.size();
	   map<char,int> mp,ang;
	   for(auto c:pat)
	   {
	       ang[c]++;
	   }
	   while(j<n)
	   {
	       if(j-i+1 < k)
	       {
	           mp[txt[j]]++;
	           ++j;
	       }
	       else if(j-i+1 ==k)
	       {
	           mp[txt[j]]++;
	           if(isAnagram(ang,mp)==true)
	           ++count;
	           mp[txt[i]]--;
	           ++i , ++j;
	       }
	   }
	   
	   return count;
	    // code here
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends