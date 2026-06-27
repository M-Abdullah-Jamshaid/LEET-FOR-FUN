class Solution {
public:
      vector<vector<int>> g;
    int ans = 0;
    int K;
    vector<long long> val;

    long long dfs(int u, int p) {
        long long sum = val[u];

        for (int v : g[u]) {
            if (v == p) continue;
            sum += dfs(v, u);
        }

        if (sum % K == 0) {
            ans++;
            return 0;   // cut here
        }

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        g.assign(n, {});
        val.assign(values.begin(), values.end());
        K = k;

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        dfs(0, -1);
        return ans;
    }
};