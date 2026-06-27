class Solution {
public:
    bool canFormPairs(vector<int>& nums, int p, int maxDiff) {
        int count = 0;
        int i = 0;
        int n = nums.size();
        while (i < n - 1) {
            if (nums[i+1] - nums[i] <= maxDiff) {
                count++;
                i += 2; // skip next index since it's already paired
            } else {
                i++;
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canFormPairs(nums, p, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
