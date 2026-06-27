class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum_power = 0;
        for (int b : batteries) {
            sum_power += b;
        }

        long long left = 1;
        long long right = sum_power / n; // Theoretical max limit
        long long ans = 0;

        while (left <= right) {
            long long target_time = left + (right - left) / 2;
            long long current_power = 0;

            // Calculate usable power for this target_time
            for (int b : batteries) {
                if (b < target_time) {
                    current_power += b;
                } else {
                    current_power += target_time; // Cap contribution at target_time
                }
            }

            // Check if we have enough power to run n computers for target_time
            if (current_power >= (long long)n * target_time) {
                ans = target_time; // Store feasible time
                left = target_time + 1; // Try to maximize
            } else {
                right = target_time - 1; // Impossible, reduce time
            }
        }

        return ans;
    }
};