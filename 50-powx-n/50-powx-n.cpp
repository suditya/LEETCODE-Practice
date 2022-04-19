class Solution {
public:
    
    double f(double x, int n)
    {
        if(n==0) return 1;
        else if (n==1) return x;
        else
        {
            double y=f(x,n/2);
            if(n%2==0) return (y*y);
            else return (y*y*x);
        }
    }
    
    double myPow(double x, int n) 
    {
         int m=abs(n);
        double ans=f(x,m);
        // if(ans==0) return 0;
        if(n<0)
        {
            return (1/ans);
        }
        // else if(ans==0) return 0;
        else
            return ans;
    }
};