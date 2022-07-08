class Solution {
public:
    double f(double x, int n)
    {
        if(n==0) return 1;
        else if(n==1) return x;
        else
        {
            double temp=f(x,n/2);
            if((n&1)==0)
            {
                return temp*temp;
            }
            else
            {
                return temp*temp*x;
            }
        }
    }
    
    double myPow(double x, int n) 
    {
        if(n>=0)
        return f(x,n);
        else
            return (1/f(x,n));
    }
};