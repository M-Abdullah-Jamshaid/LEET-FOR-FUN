class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            sort(grid[i].begin(),grid[i].end());
        }
        int ans = 0;
        for(int j = grid[0].size()-1; j >= 0; j--){
            int max = INT_MIN;
            for(int i = 0; i < grid.size(); i++){
                if(grid[i][j] > max) max = grid[i][j];
            }
            ans += max;
        }
        return ans;
    }
};