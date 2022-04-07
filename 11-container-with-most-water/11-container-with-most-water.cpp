class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        //learn 2 pointer approach and solve it 
        int ans = 0;
        int i = 0, j = height.size() - 1;          
        while(i < j){
            ans = max(ans, (j - i) * min(height[i], height[j]));
            height[i] > height[j] ? j-- : i++;  
        }
        
        return ans;   
    }
};