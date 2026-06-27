class Solution {
public:
    int specialTriplets(vector<int>& nums) {
         long long ans = 0;
        int MOD = 1e9 + 7;
        
        vector<int> freqRight(100001, 0);
        vector<int> freqLeft(100001, 0);

        for (int x : nums) {
            freqRight[x]++;
        }

        for (int x : nums) {
            freqRight[x]--;

            long long target = (long long)x * 2;

            if (target <= 100000) {
                long long combinations = (long long)freqLeft[target] * freqRight[target];
                ans = (ans + combinations) % MOD;
            }

            freqLeft[x]++;
        }

        return ans;
    }
};