class Solution {
public:
    int n ;
    int m ;
    int dp[205][205];
    int getVal(vector<vector<int>> &mat, int i=0, int j=0)
    {
        
        // Base case : we have crossed the matrix, ie. out of bound
        /// if current row crosses then my row is below the princess or 
        /// if current column crosses then my column is ahead the column of princess
        /// and beacause we can go only down and right so we wont be able reach princess
        if(i == n || j == m)    return 1e9; 
        if(dp[i][j]!=-1) return dp[i][j];
		// Base Case : we have reached our destination ie. last cell
        /// we reached princess , cheers return this cost;
        if(i == n-1 and j == m-1)   
            return (mat[i][j] <= 0) ? -mat[i][j] + 1 : 1;
        
        /// now we must try all possible paths , we ask our right and and down cell
        int IfWeGoRight = getVal(mat , i , j+1);
        int IfWeGoDown = getVal(mat , i+1 , j);
        
        /// min of either values and then cost of this cell
        int minHealthRequired =  min(IfWeGoRight , IfWeGoDown) -mat[i][j];
        
        /// point 2 as explained 
        return dp[i][j]=( minHealthRequired <= 0 ) ? 1 : minHealthRequired;      
    }
    int calculateMinimumHP(vector<vector<int>>& mat) 
    {
        n= mat.size();
        m= mat[0].size();
        memset(dp,-1,sizeof(dp));
        return getVal(mat);     
    }
};