class Solution {
public:
    bool canAchieve(vector<int>& stations, int r, long long k, long long minPower) {
        int n = stations.size();
        vector<long long> added(n, 0);
        long long window = 0;
        for (int i = 0; i <= min(r, n - 1); i++) window += stations[i];

        for (int i = 0; i < n; i++) {
            int left = i - r - 1;
            int right = i + r;
            if (left >= 0) window -= stations[left] + added[left];
            if (right < n && i > 0) window += stations[right];

            if (window < minPower) {
                long long need = minPower - window;
                if (k < need) return false;
                added[min(n - 1, i + r)] += need;
                window += need;
                k -= need;
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        long long low = 0, high = 1e15, ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canAchieve(stations, r, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
