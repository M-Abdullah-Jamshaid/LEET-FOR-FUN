class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size());
        int p = 0;

        for (int i = 0; i < nums.size(); i++) {
            p = (p * 2 + nums[i]) % 5;
            ans[i] = (p == 0);
        }

        return ans;
    }
};
