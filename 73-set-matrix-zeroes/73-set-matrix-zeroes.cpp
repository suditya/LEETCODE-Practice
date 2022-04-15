class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        set<int> row,col;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        
        for(int i=0;i<n;i++) //rows 
        {
            if(row.find(i)!=row.end())
            {
                for(int j=0;j<m;j++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<m;i++) //cols
        {
            if(col.find(i)!=col.end())
            {
                for(int j=0;j<n;j++)
                {
                    matrix[j][i]=0;
                }
            }
        }
        
    }
};