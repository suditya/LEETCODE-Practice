class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int possiblePairValue = target - num;
            if (hash.find(possiblePairValue) !=
                hash.end()) // means it exists then
            {
                return {i, hash[possiblePairValue]};
            }

            hash[num] = i;
        }
        return {-1, -1};
    }
};