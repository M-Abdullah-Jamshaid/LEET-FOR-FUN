class Solution {
public:
    int minimumK(vector<int>& nums) {
        int low = 1;
        int high =
            max((int)nums.size(), *max_element(nums.begin(), nums.end()));
        int ans = high;
        while (low <= high) {
            long long k = low + (high - low) / 2;
            long long bug = k * k;
            long long hit = 0;
            bool possible = true;
            for (int x : nums) {
                hit += (x + k - 1) / k;

                if (hit > bug) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                ans = k;
                high = k - 1;
            } else {

                low = k + 1;
            }
        }
        return ans;
    }
};