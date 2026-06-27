class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            long long tempmax = *max_element(nums.begin(), nums.begin() + i);
            long long tempmin = *min_element(nums.begin() + i, nums.end());
            if (tempmax - tempmin <= k) {
                return i;
            }
        }

        return -1;
    }
};