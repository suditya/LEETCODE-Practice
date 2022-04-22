class Solution {
public:
    int findDuplicate(vector<int>& a) 
    {
        int fast=0,slow=0;
        while(1)
        {
            slow=a[slow];
            fast=a[a[fast]];
            if(slow==fast)
                break;
        }
        int slow2=0;
        while(1)
        {
            slow=a[slow];
            slow2=a[slow2];
            if(slow==slow2)
                break;
        }
        return slow;
    }
};