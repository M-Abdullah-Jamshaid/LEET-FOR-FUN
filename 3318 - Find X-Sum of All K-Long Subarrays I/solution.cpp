class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++) {
            vector<int> sub(nums.begin() + i, nums.begin() + i + k);
            unordered_map<int, int> freq;

            // Count frequencies
            for (int num : sub) freq[num]++;

            // Move to vector for sorting
            vector<pair<int, int>> vec(freq.begin(), freq.end());

            // Sort by frequency desc, then value desc
            sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
                if (a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });

            // Keep only top x elements
            unordered_set<int> top;
            for (int j = 0; j < x && j < vec.size(); j++)
                top.insert(vec[j].first);

            // Calculate sum of elements in sub that are in top x
            int total = 0;
            for (int num : sub)
                if (top.count(num))
                    total += num;

            ans.push_back(total);
        }
        return ans;
    }
};