class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int nn = m+n-2;
        int rr = min(m-1,n-1);
        double ans = 1;
        
        for(double i=1;i<=rr;i++){
            ans *=(nn--)/i;
        }
        
        if(ans > int(ans)+0.5){
            return ceil(ans);
        }
       return int(ans);
    }
};