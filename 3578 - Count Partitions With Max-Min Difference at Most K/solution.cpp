class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        int MOD = 1e9 + 7;

        // dp[i] stores the number of ways to partition the prefix of length i.
        // dp[0] = 1 means there is 1 way to partition an empty array.
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        // prefix_dp[i] stores the sum of dp[0]...dp[i-1].
        // This helps us calculate range sums in O(1).
        vector<int> prefix_dp(n + 2, 0);
        prefix_dp[1] = 1; // prefix_dp[1] corresponds to sum up to dp[0]

        // Deques to store indices for min and max within the current window
        deque<int> min_dq, max_dq;
        int left = 0;

        for (int i = 0; i < n; ++i) {
            // Maintain max_dq: decreasing order of values
            while (!max_dq.empty() && nums[max_dq.back()] <= nums[i]) {
                max_dq.pop_back();
            }
            max_dq.push_back(i);

            // Maintain min_dq: increasing order of values
            while (!min_dq.empty() && nums[min_dq.back()] >= nums[i]) {
                min_dq.pop_back();
            }
            min_dq.push_back(i);

            // Shrink the window from the left if the condition is violated
            while (nums[max_dq.front()] - nums[min_dq.front()] > k) {
                left++;
                // Remove indices that are now outside the window [left, i]
                if (max_dq.front() < left) max_dq.pop_front();
                if (min_dq.front() < left) min_dq.pop_front();
            }

            // The last segment ends at i. Valid start indices for this segment are [left, i].
            // If the last segment is nums[j...i], the previous partitions were for prefix length j.
            // We sum dp[j] for all j in [left, i].
            // Sum = prefix_dp[i+1] - prefix_dp[left]
            
            int current_ways = (prefix_dp[i + 1] - prefix_dp[left] + MOD) % MOD;
            dp[i + 1] = current_ways;

            // Update prefix sum for the next iteration
            prefix_dp[i + 2] = (prefix_dp[i + 1] + current_ways) % MOD;
        }

        return dp[n];
    }
};