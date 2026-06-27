class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> minPref(k, LLONG_MAX);
        long long pref = 0;            // corresponds to P[0] initially
        long long ans = LLONG_MIN;

        // iterate prefix index t from 0..n
        // P[t] = sum of first t elements (nums[0..t-1])
        for (int t = 0; t <= n; ++t) {
            int r = t % k;
            if (minPref[r] != LLONG_MAX) {
                ans = max(ans, pref - minPref[r]);
            }
            minPref[r] = min(minPref[r], pref);

            // advance pref to next P[t+1]
            if (t < n) pref += nums[t];
        }

        return ans;
    }
};
