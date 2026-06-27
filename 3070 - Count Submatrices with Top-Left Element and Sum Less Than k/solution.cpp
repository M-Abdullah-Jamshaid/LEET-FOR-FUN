
class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        int size = grid.size();
        int ans[m][n];
        // int temptop = 0;
        // int templeft = 0;
        // int top = 0;
        // int left = 0;
        // for (int i = 0; i < grid.size(); i++)
        // {
        //     for (int j = 0; j < grid.size(); j++)
        //     {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

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

        // for (int i = 0; i < grid.size(); i++)
        // {
        //     for (int j = 0; j < grid.size(); j++)
        //     {
        //         cout << ans[i][j] << " ";
        //     }
        //     cout << endl;
        // }

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
        // cout << endl;

        // for (int i = 0; i < grid.size(); i++)
        // {
        //     for (int j = 0; j < grid.size(); j++)
        //     {
        //         cout << ans[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // for (int i = 0; i < grid.size(); i++)
        // {
        //     for (int k = 0; k < grid.size(); k++)
        //     {

        //         temptop = i - 1;
        //         templeft = k - 1;
        //         cout << grid[i][k] << " = = ";
        //         if (templeft >= 0 && temptop >= 0)
        //         {
        //             left = grid[i][templeft];
        //             top = ans[temptop][k];
        //             // cout << grid[i][k];
        //         }
        //         else if (templeft >= 0)
        //         {
        //             left = grid[i][templeft];
        //             top = 0;
        //         }
        //         else if (temptop >= 0)
        //         {
        //             left = 0;
        //             top = ans[temptop][k];
        //         }
        //         else
        //         {
        //             left = 0;
        //             top = 0;
        //         }
        //         ans[i][k] = grid[i][k] + top + left;
        //         cout << ans[i][k] << " ";
        //     }
        //     cout << endl;
        // }

        // for (int i = 0; i < grid.size(); i++)
        // {
        //     for (int j = 0; j < grid.size(); j++)
        //     {
        //         cout << ans[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (
                    ans[i][j] <= k)
                {
                    count++;
                }
            }
        }

        return count;
    }
};