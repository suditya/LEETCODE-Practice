class Solution {
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
    
	vector<int> search(string pat, string txt) 
	{
	   // int count=0;
       vector<int> ans;
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
	           ans.push_back(i);
	           mp[txt[i]]--;
	           ++i , ++j;
	       }
	   }
	   
	   return ans;
	    // code here
	}
    
    vector<int> findAnagrams(string s, string p) {
        
        return search(p,s);
    }
};