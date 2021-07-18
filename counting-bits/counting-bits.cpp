class Solution {
public:
    vector<int> countBits(int n) 
    {
        if(n==0)
            return {0};
        if(n==1)
            return {0,1};
        vector<int> ans=countBits(n-1);
        int count=0;
        while(n)
        {
            if(n&1)
                ++count;
            n=n>>1;
        }
        ans.push_back(count);
        return ans;
        
    }
};