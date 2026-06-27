class Solution {
public:
     
    int assignEdgeWeights(vector<vector<int>>& edges, int res = -1) {
    vector<vector<int>> g(edges.size()+2);
    for(const auto& x : edges) g[min(x[0], x[1])].push_back(max(x[0],x[1])); // use min max trick, no need to add seen
    queue<int> q{{1}};
    while(!q.empty()){
        for(int w=q.size(); w; --w){
            int i = q.front(); q.pop();
            for(int x : g[i]) q.push(x);
        }
        res = res==-1 ? 0 : !res ? 1 : (res*2)%1000000007;
    }
    return res; // pow(2, level-2)
}
};