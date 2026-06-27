class Solution {
public:
    bool isLetter(char c) { return (c >= 'a' && c <= 'z'); }
    string reverseByType(string s) {
        int n = s.length();

        int start = 0;
        int end = n - 1;

        while (start < end) {
            if (!isLetter(s[start])) {
                start++;
            } else if (!isLetter(s[end])) {
                end--;
            } else {
                swap(s[start], s[end]);
                start++;
                end--;
            }
        }

        start = 0;
        end = n - 1;

        while (start < end) {
            if (isLetter(s[start])) {
                start++;
            } else if (isLetter(s[end])) {
                end--;
            } else {
                swap(s[start], s[end]);
                start++;
                end--;
            }
        }
        return s;
    }
};