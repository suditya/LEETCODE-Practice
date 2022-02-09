class Solution {
public:
    
    int res;

    void bs(vector<char>& a, char x,int i,int j)
    {
        if(i>j) return ;
        else
        {
            int mid=i+(j-i)/2;
            if(a[mid]>x)
            {
                res=mid;
                bs(a,x,i,mid-1);
            }
            else
                bs(a,x,mid+1,j);
        }
    }
    
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        res=0;
        bs(letters,target,0,letters.size()-1);
        return letters[res];
    }
};