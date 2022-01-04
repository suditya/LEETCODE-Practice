class Solution {
public:
    int bitwiseComplement(int n) 
    {
        
        int i=0;
        if(n==0 or n==1)
            return (n^1);
        int length=log2(n)+1;
       
        cout<<length<<"\n";
        while(i<=length-1)
        {
            
            int x=(1<<i);
            n=(n^(x));
            cout<<n<<" "<<x<<"\n";
            ++i;
        }
        return n;
    }
};