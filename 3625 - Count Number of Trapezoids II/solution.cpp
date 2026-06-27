class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4)
            return 0;

        map<pair<int, int>, map<long long, int>> lines;

        map<pair<int, int>, map<pair<int, int>, int>> midpoints;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long x1 = points[i][0], y1 = points[i][1];
                long long x2 = points[j][0], y2 = points[j][1];

                int dy = y1 - y2;
                int dx = x1 - x2;
                int g = gcd(abs(dy), abs(dx));
                dy /= g;
                dx /= g;

                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }
                pair<int, int> slope = {dy, dx};

                long long intercept = (long long)dy * x1 - (long long)dx * y1;

                lines[slope][intercept]++;

                midpoints[{(int)(x1 + x2), (int)(y1 + y2)}][slope]++;
            }
        }

        long long totalTrapezoids = 0;

        for (auto const& [slope, interceptMap] : lines) {
            long long sumCounts = 0;
            long long sumSqCounts = 0;

            for (auto const& [intercept, count] : interceptMap) {
                sumCounts += count;
                sumSqCounts += (long long)count * count;
            }

            totalTrapezoids += (sumCounts * sumCounts - sumSqCounts) / 2;
        }

        for (auto const& [mid, slopeMap] : midpoints) {
            long long sumCounts = 0;
            long long sumSqCounts = 0;

            for (auto const& [slope, count] : slopeMap) {
                sumCounts += count;
                sumSqCounts += (long long)count * count;
            }

            totalTrapezoids -= (sumCounts * sumCounts - sumSqCounts) / 2;
        }

        return (int)totalTrapezoids;
    }
};