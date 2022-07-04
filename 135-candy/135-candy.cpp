class Solution {
public:
   int candy(vector<int>& rat) {
        vector<int> fwd(rat.size(), 1);
        for(int i = 1; i<rat.size(); i++) 
            if( rat[i] > rat[i-1] )    fwd[i] = fwd[i-1] + 1;
        for(int i = rat.size()-1; i>0; i--)  
            if( rat[i-1] > rat[i])     fwd[i-1] = max(fwd[i] + 1, fwd[i-1]);
        return accumulate(fwd.begin(), fwd.end(), 0);
    }
};