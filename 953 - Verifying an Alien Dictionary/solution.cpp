class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> map(26, 0);
        for (int i = 0; i < 26; i++) {
            map[order[i] - 'a'] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = 0; j < min(words[i].size(), words[i + 1].size());
                 j++) {
                if (map[words[i][j] - 'a'] < map[words[i + 1][j] - 'a']) {
                    break;
                } else if (map[words[i][j] - 'a'] >
                           map[words[i + 1][j] - 'a']) {
                    return false;
                }
                if (words[i].size() > words[i + 1].size() &&
                    j == min(words[i].size(), words[i + 1].size()) - 1) {
                    return false;
                }
            }
        }
        return true;
    }
};