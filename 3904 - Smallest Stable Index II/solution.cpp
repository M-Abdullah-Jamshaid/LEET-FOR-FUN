class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> velqanidor = nums;

        vector<int> beack(n);
        beack[0] = velqanidor[0];
        for (int i = 1; i < n; i++) {
            beack[i] = max(beack[i - 1], velqanidor[i]);
        }

        vector<int> ladt(n);
        ladt[n - 1] = velqanidor[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            ladt[i] = min(ladt[i + 1], velqanidor[i]);
        }

        for (int i = 0; i < n; i++) {
            if (beack[i] - ladt[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};