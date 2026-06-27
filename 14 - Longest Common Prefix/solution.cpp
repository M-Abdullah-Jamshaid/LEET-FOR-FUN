class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Initialize prefix with the first string
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            // Find the position of prefix in strs[i]
            // If it's not at index 0, shorten the prefix
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};