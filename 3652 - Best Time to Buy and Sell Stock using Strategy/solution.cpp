class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long initial_profit = 0;

        for (int i = 0; i < n; ++i) {
            initial_profit += (long long)strategy[i] * prices[i];
        }

        auto get_gain = [&](int i, int target) {
            return (long long)(target - strategy[i]) * prices[i];
        };

        long long current_gain = 0;
        int half_k = k / 2;
        
        for (int i = 0; i < half_k; ++i) {
            current_gain += get_gain(i, 0);
        }
        for (int i = half_k; i < k; ++i) {
            current_gain += get_gain(i, 1);
        }

        long long max_gain = current_gain;

        for (int i = 1; i <= n - k; ++i) {
            current_gain -= get_gain(i - 1, 0);

            current_gain -= get_gain(i + half_k - 1, 1);
            current_gain += get_gain(i + half_k - 1, 0);

            current_gain += get_gain(i + k - 1, 1);

            max_gain = max(max_gain, current_gain);
        }

        return initial_profit + max(0LL, max_gain);
    }
};