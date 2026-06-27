class Solution
{
public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        long long ans[m][n];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                {
                    ans[i][j] = grid[i][j];
                }
                else
                {

                    ans[i][j] = grid[i][j] + ans[i][j - 1];
                }
            }
        }

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                if (j == 0)
                {
                    ans[j][i] = ans[j][i];
                }
                else
                {

                    ans[j][i] = ans[j][i] + ans[j - 1][i];
                }
            }
        }

        for (int i = 0; i < m; i++)
        {

            if (ans[i][n - 1] == ans[m - 1][n - 1] - ans[i][n - 1])
            {
                return true;
            }
        }
        for (int i = 0; i < n; i++)
        {

            if (ans[m - 1][i] == ans[m - 1][n - 1] - ans[m - 1][i])
            {
                return true;
            }
        }
      

        return false;
    }
};