#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> diff(m, vector<int>(n, 0));
        vector<vector<int>> xCount(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = 0;
                int hasX = 0;
                
                if (grid[i][j] == 'X') {
                    val = 1;
                    hasX = 1;
                } else if (grid[i][j] == 'Y') {
                    val = -1;
                }
                
                diff[i][j] = val;
                xCount[i][j] = hasX;
                
                if (i > 0) {
                    diff[i][j] += diff[i - 1][j];
                    xCount[i][j] += xCount[i - 1][j];
                }
                if (j > 0) {
                    diff[i][j] += diff[i][j - 1];
                    xCount[i][j] += xCount[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    diff[i][j] -= diff[i - 1][j - 1];
                    xCount[i][j] -= xCount[i - 1][j - 1];
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (xCount[i][j] > 0 && diff[i][j] == 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
};