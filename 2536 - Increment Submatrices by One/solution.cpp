class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        for(vector<int> q:queries){
            int r1 = q[0],c1=q[1],r2 = q[2], c2 = q[3];
            for(int i=r1;i<=r2;i++){
                for(int j=c1;j<=c2;j++){
                    mat[i][j]+=1;
                }
            }
        }
        return mat;
    }
};