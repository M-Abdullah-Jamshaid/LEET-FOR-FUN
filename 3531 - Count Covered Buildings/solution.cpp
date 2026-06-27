class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> minRowY(n + 1, INT_MAX);
        vector<int> maxRowY(n + 1, INT_MIN);
        vector<int> minColX(n + 1, INT_MAX);
        vector<int> maxColX(n + 1, INT_MIN);

        for (const auto& b : buildings) {
            int x = b[0];
            int y = b[1];

            if (y < minRowY[x]) minRowY[x] = y;
            if (y > maxRowY[x]) maxRowY[x] = y;

            if (x < minColX[y]) minColX[y] = x;
            if (x > maxColX[y]) maxColX[y] = x;
        }

        int count = 0;

        // Step 2: Check logic
        for (const auto& b : buildings) {
            int x = b[0];
            int y = b[1];

            bool rowCovered = (y > minRowY[x] && y < maxRowY[x]);

            bool colCovered = (x > minColX[y] && x < maxColX[y]);

            if (rowCovered && colCovered) {
                count++;
            }
        }

        return count;
    }
};