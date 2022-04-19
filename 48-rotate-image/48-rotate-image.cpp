class Solution {
public:
    void transpose(vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        // int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                // cout<<i<<" "<<j<<"\n";
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) 
    {
        transpose(matrix);
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                swap(matrix[i][j],matrix[i][(n-j)-1]);
            }
        }
    }
};