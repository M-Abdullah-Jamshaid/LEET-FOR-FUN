class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeros;

        for (int i = 0; i < n; i++) {
            int zeros = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) zeros++;
                else break;
            }
            trailingZeros.push_back(zeros);
        }

        int totalSwaps = 0;

        for (int i = 0; i < n; i++) {
            int required = n - 1 - i;
            int foundIdx = -1;

            for (int j = i; j < n; j++) {
                if (trailingZeros[j] >= required) {
                    foundIdx = j;
                    break;
                }
            }

            if (foundIdx == -1) return -1;

            while (foundIdx > i) {
                swap(trailingZeros[foundIdx], trailingZeros[foundIdx - 1]);
                totalSwaps++;
                foundIdx--;
            }
        }

        return totalSwaps;
    }
};