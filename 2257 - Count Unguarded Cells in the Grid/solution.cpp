class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); 
        // 0 = empty, 1 = wall, 2 = guard, 3 = guarded

        for (auto &w : walls) grid[w[0]][w[1]] = 1;
        for (auto &g : guards) grid[g[0]][g[1]] = 2;

        vector<int> dirX = {1, -1, 0, 0};
        vector<int> dirY = {0, 0, 1, -1};

        // For each guard, mark visible cells
        for (auto &g : guards) {
            int r = g[0], c = g[1];
            for (int d = 0; d < 4; ++d) {
                int x = r + dirX[d], y = c + dirY[d];
                while (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] != 1 && grid[x][y] != 2) {
                    if (grid[x][y] == 0) grid[x][y] = 3; // mark as guarded
                    x += dirX[d];
                    y += dirY[d];
                }
            }
        }

        // Count unguarded (0 = empty)
        int count = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0)
                    count++;

        return count;
    }
};