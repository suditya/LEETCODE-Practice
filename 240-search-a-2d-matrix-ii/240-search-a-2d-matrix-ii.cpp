class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int x=0;
        int row=matrix.size();
        int y=matrix[0].size()-1;
        while(1)
        {
            if(x==row or y<0) break;
            // cout<<matrix[x][y]<<"\n";
            if(matrix[x][y]==target) return true;
            else if(matrix[x][y] < target)
            {
                ++x;
            }
            else
            {
                --y;
            }
        }
        
        return false;
    }
};