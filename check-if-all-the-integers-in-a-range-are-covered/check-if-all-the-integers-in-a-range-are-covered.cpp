class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) 
    {
        for(int i=left;i<=right;i++)
        {
            bool flag=false;
            for(int j=0;j<ranges.size();j++)
            {
                if(i>=ranges[j][0] and i<=ranges[j][1])
                {
                    flag=true;
                    break;
                }
            }
            if(!flag) return false;
        }
        return true;
    }
};