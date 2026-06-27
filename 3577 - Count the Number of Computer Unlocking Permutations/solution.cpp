class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        long long n = complexity.size();
        long long MOD = 1e9 + 7;
        
        int rootComplexity = complexity[0];
        
        for (int i = 1; i < n; ++i) {
            if (complexity[i] <= rootComplexity) {
                return 0;
            }
        }
        
        long long ans = 1;
        for (int i = 1; i < n; ++i) {
            ans = (ans * i) % MOD;
        }
        
        return (int)ans;
    }
};