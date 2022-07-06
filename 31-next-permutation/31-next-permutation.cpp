class Solution {
public:
    void nextPermutation(vector<int>& a) 
    {
        int n=a.size();
        int pivot=-1;
        for(int i=n-1;i>0;i--)
        {
            if(a[i] > a[i-1])
            {
                pivot=i-1;
                break;
            }
        }
        if(pivot==-1)
        {
            reverse(a.begin(),a.end());
            return ;
        }
        else
        {
            cout<<pivot<<" ";
            int mini=INT_MIN,miniIndex=-1;
            for(int i=n-1;i>pivot;i--)
            {
                if(a[i]>a[pivot])
                {
                    mini=a[i];
                    miniIndex=i;
                    break;
                }
            }
            swap(a[miniIndex],a[pivot]);
            sort(a.begin()+pivot+1,a.end());
            return ;
        }
    }
};