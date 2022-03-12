class Solution {
public:
    bool isPalindrome(string S)
    {
        for (int i = 0; i < S.length() / 2; i++) {
            if (S[i] != S[S.length() - i - 1]) {
                return false;
            }
        }
        return true;
    }
 
    int maxProduct(string s) 
    {
        int n=s.size();
        // cout<<n;
        int z=(1<<n);
        // cout<<z;
        unordered_map<int,int> mp;
        for(int mask=1;mask<z;mask++)
        {
            string subsequence="";
            for(int j=0;j<n;j++)
            {
                if(((1<<j)&mask))
                {
                    // cout<<"hey ";
                    subsequence.push_back(s[j]);
                    // subsequence+=s[n-1-j];
                }
            }
            // cout<<subsequence<<" ";
            if(isPalindrome(subsequence)==true)
            {
                mp[mask]=subsequence.size();
            }
        }
        int ans=0;
        for(auto a:mp)
        {
            for(auto b:mp)
            {
                int aMask=a.first,bMask=b.first;
                int aLen=a.second,bLen=b.second;
                // cout<<aMask<<" "<<bMask<<" "<<aLen<<" "<<bLen<<"\n";
                if((aMask&bMask)==0)
                {
                    ans=max(ans,(aLen*bLen));
                }
            }
        }
        return ans;
    }
};