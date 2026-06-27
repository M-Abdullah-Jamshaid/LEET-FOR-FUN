class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        long long INF = -1e18; 

        vector<vector<long long>> dp(k + 1, vector<long long>(3, INF));

        dp[0][0] = 0;

        for (int price : prices) {
            vector<vector<long long>> next_dp(k + 1, vector<long long>(3, INF));

            next_dp[0][0] = 0; 

            for (int t = 1; t <= k; ++t) {
                long long sellLong = (dp[t][1] != INF) ? dp[t][1] + price : INF;
                long long coverShort = (dp[t][2] != INF) ? dp[t][2] - price : INF;
                
                next_dp[t][0] = max({dp[t][0], sellLong, coverShort});

                if (dp[t-1][0] != INF) {
                    next_dp[t][1] = max(dp[t][1], dp[t-1][0] - price);
                } else {
                    next_dp[t][1] = dp[t][1];
                }

                if (dp[t-1][0] != INF) {
                    next_dp[t][2] = max(dp[t][2], dp[t-1][0] + price);
                } else {
                    next_dp[t][2] = dp[t][2];
                }
            }
            dp = next_dp;
        }

        long long max_profit = 0;
        for (int t = 0; t <= k; ++t) {
            max_profit = max(max_profit, dp[t][0]);
        }

        return max_profit;
    }
};