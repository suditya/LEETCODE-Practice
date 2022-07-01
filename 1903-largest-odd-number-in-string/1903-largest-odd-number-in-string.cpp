class Solution {
public:
    bool isOdd(char c)
    {
        int num=int(c)-'0';
        // cout<<c<<" "<<num<<"\n";
        if((num&1)!=0) return true;
        else return false;
    }
    
    string largestOddNumber(string num) 
    {
        int n=num.size();
        int lastPositionOddNum=-1;
        for(int i=n-1;i>=0;i--)
        {
            char c=num[i];
            if(isOdd(c)==true)
            {
                lastPositionOddNum=i;
                break;
            }
        }
        string res;
        for(int i=0;i<=lastPositionOddNum;i++)
            res.push_back(num[i]);
        return res;
    }
};