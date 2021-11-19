class Solution {
public:
    void sortColors(vector<int>& ar) 
    {
     
        int a=0,b=0,c=0;
        for(int i=0;i<ar.size();i++)
        {
            if(ar[i]==0)
                ++a;
            else if(ar[i]==1)
                ++b;
            else
                ++c;
        }
        cout<<a<<" "<<b<<" "<<c;
        for(int i=0;i<a;i++)
        {
             ar[i]=0;
        }
        for(int i=a;i<a+b;i++)
        {
             ar[i]=1;
        }
        for(int i=a+b;i<a+b+c;i++)
        {
             ar[i]=2;
        }
        
    }
};