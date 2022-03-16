class Solution {
public:
    bool isPalindrome(string &s, int start, int end) {
	
	while(start <= end) {
		if(s[start++] != s[end--])                               return false;
	}

    return true;
}

int mincutHelper(string s, int i, int j, vector<vector<int>> &dp) {
    
    // Base Condition
    
    // if string is empty or a single character, then Zero partition
    if(i >= j)                                                 return dp[i][j] = 0;
	
	// if value already present at index (i, j) in dp, then return the value
    if(dp[i][j] != -1)                                         return dp[i][j];
    
	// if substring of s in range [i, j] is a palindrome, the we don't need to do any partition i.e Min partitions  = 0
    if(isPalindrome(s, i, j) == true)                          return dp[i][j] = 0;
    
    int mini = INT_MAX;
    
    // Run for loop from i to j-1
    for(int k=i; k<=j-1; k++) {
        
		// if subtring of s in range [i, k] is a palindrome, then run the recursive function in range [k+1, j]
        if(isPalindrome(s, i, k) == true) {            
                mini = min(mini, 1 + mincutHelper(s, k + 1, j, dp));
        }
    }
    
    dp[i][j] = mini;
    return mini;
}

int minCut(string s) {

    vector<vector<int>> dp;
    
    int n = s.length();
    if(n == 0)                                              return 0;
    
    dp.resize(n, vector<int>(n, -1));
    
    return mincutHelper(s, 0, n-1, dp);
}


};