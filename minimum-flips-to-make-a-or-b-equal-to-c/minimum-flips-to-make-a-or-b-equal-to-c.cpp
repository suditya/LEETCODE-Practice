class Solution {
public:
    int minFlips(int a, int b, int c) 
    {
        if((a|b) == c) 
        {
            cout<<c<<" "<<(a or b)<<"\n";
            return 0;
        }    
        else
        {
            int count=0;
            for(int i=0;i<32;i++)
            {
                int x=(a>>i)&1;
                int y=(b>>i)&1;
                int z=(c>>i)&1;
                cout<<x<<" "<<y<<" "<<z<<"\n";
                if((x or y )!= z)
                {
                    if(z==1)
                        ++count;
                    else
                    {
                        if(x==1) ++count;
                        if(y==1) ++count;
                    }
                }
            }
            return count;
        }
        
    }
};