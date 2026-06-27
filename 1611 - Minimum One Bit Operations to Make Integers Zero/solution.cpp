class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res = 0;
        for (; n; n >>= 1) {
            res ^= n;
        }
        return res;
    }
};