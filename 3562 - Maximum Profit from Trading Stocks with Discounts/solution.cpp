class Solution {
public:
    int n_emp;
    int limit;
    vector<int> present_prices;
    vector<int> future_prices;
    vector<vector<int>> adj;
    
    vector<int> merge(const vector<int>& A, const vector<int>& B) {
        vector<int> C(limit + 1, -1e9); // Initialize with -infinity
        
        for (int i = 0; i <= limit; ++i) {
            if (A[i] == -1e9) continue; // Skip invalid states
            for (int j = 0; j <= limit - i; ++j) {
                if (B[j] == -1e9) continue;
                C[i + j] = max(C[i + j], A[i] + B[j]);
            }
        }
        return C;
    }

    pair<vector<int>, vector<int>> dfs(int u) {
        vector<int> children_if_u_buys(limit + 1, -1e9);
        children_if_u_buys[0] = 0;
        
        vector<int> children_if_u_skips(limit + 1, -1e9);
        children_if_u_skips[0] = 0;

        for (int v : adj[u]) {
            pair<vector<int>, vector<int>> child_res = dfs(v);
            children_if_u_buys = merge(children_if_u_buys, child_res.first);
            children_if_u_skips = merge(children_if_u_skips, child_res.second);
        }

        int cost_half = present_prices[u] / 2;
        int profit_half = future_prices[u] - cost_half;
        
        vector<int> res_with_discount = children_if_u_skips; 
        for (int w = 0; w <= limit - cost_half; ++w) {
            if (children_if_u_buys[w] != -1e9) {
                res_with_discount[w + cost_half] = max(res_with_discount[w + cost_half], children_if_u_buys[w] + profit_half);
            }
        }

        int cost_full = present_prices[u];
        int profit_full = future_prices[u] - cost_full;
        
        vector<int> res_without_discount = children_if_u_skips;
        for (int w = 0; w <= limit - cost_full; ++w) {
            if (children_if_u_buys[w] != -1e9) {
                res_without_discount[w + cost_full] = max(res_without_discount[w + cost_full], children_if_u_buys[w] + profit_full);
            }
        }

        return {res_with_discount, res_without_discount};
    }

    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        n_emp = n;
        limit = budget;
        present_prices = present;
        future_prices = future;
        
        
        adj.assign(n, vector<int>());
        for (const auto& edge : hierarchy) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
        }

        pair<vector<int>, vector<int>> result = dfs(0);

        int max_p = 0;
        for (int p : result.second) {
            max_p = max(max_p, p);
        }
        
        return max_p;
    }
};