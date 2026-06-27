class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> seen; 
        for (const string& s : nums) {
            seen.insert(stoi(s, nullptr, 2));
        }

        int res = 0;
        for (int i = 0; i <= n; i++) {
            if (seen.find(i) == seen.end()) {
                res = i;
                break;
            }
        }

        int x = nums[0].length();
        string bi = bitset<16>(res).to_string();
        return bi.substr(16 - x);
    }
};