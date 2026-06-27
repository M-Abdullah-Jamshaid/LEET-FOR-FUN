class Solution {
public:
    int findPaths(vector<vector<int>>& grid,int curr, int k,int m,int n,vector<vector<vector<int>>>& memo,int r,int c){
        if (r >= m || c >= n) return 0;
        int new_r = (curr + grid[r][c])%k;
        if(r==m-1 && c==n-1){
            return (new_r%k==0);
        }
        if (memo[r][c][new_r] != -1) {
            return memo[r][c][new_r];
        }
        long long down = findPaths(grid,new_r,k,m,n,memo,r+1,c);
        long long right = findPaths(grid,new_r,k,m,n,memo,r,c+1);
        int MOD = 1e9+7;
        return memo[r][c][new_r] = (down+right)% MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n= grid[0].size();
        vector<vector<vector<int>>> memo(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return findPaths(grid,0,k,m,n,memo,0,0);
    }
};