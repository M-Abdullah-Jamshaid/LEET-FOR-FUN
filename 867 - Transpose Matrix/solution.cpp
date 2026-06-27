class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> res;

        for (size_t c = 0; c < matrix[0].size(); c++) {
            vector<int> temp;

            for (size_t r = 0; r < matrix.size(); r++) {
                temp.push_back(matrix[r][c]);
            }

            res.push_back(temp);
        }

        return res;
    }
};