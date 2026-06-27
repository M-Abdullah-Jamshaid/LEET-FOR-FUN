class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        if (prices.empty())
            return 0;

        long long total_periods = 1; 
        long long current_length = 1;

        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] == prices[i - 1] - 1) {
                current_length++;
            } else {
                current_length = 1; 
            }

            total_periods += current_length;
        }

        return total_periods;
    }
};