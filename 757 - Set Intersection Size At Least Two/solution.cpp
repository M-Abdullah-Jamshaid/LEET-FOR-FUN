class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort intervals:
        // 1. By End time (Ascending)
        // 2. If End times match, by Start time (Descending)
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        });

        int res = 0;
        // p1 is the largest chosen number, p2 is the second largest.
        // Initialize to -1 (intervals start at 0, so this is safe)
        int p1 = -1; 
        int p2 = -1;

        for (const auto& interval : intervals) {
            int u = interval[0]; // current start
            int v = interval[1]; // current end

            // Check overlaps with our current right-most chosen points
            bool p1_in = (u <= p1); // Is the largest point inside this interval?
            bool p2_in = (u <= p2); // Is the second largest inside?

            if (p1_in && p2_in) {
                // Already have 2 points in this interval.
                continue;
            } 
            else if (p1_in) {
                // We have 1 point (p1), we need 1 more.
                res++;
                // We generally want to add 'v' (the end of current interval).
                // If p1 is already 'v', we add 'v-1'.
                if (p1 == v) {
                    p2 = v - 1;
                    // p1 remains v
                } else {
                    p2 = p1; // The old max becomes the 2nd max
                    p1 = v;  // The new max is the current end
                }
            } 
            else {
                // We have 0 points, we need 2.
                res += 2;
                // Pick the two largest possible values in this interval
                p2 = v - 1;
                p1 = v;
            }
        }

        return res;
    }
};