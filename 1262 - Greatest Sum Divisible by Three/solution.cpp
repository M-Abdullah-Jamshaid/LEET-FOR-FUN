class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);

        for (int num : nums) {
            vector<int> cur(dp);
            for (int r : cur) {
                int newSum = r + num;
                dp[newSum % 3] = max(dp[newSum % 3], newSum);
            }
        }
        return dp[0];
    }
};