class Solution {
public:
    int majorityElement(vector<int>& a) 
    {
        int n=a.size();
        int ansIndex=0;
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(a[ansIndex]==a[i])
                ++count;
            else
                --count;
            if(count==0)
            {
                ansIndex=i;
                count=1;
            }
        }
        cout<<count<<" "<<ansIndex;
        return a[ansIndex];
    }
};