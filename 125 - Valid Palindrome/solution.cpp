class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.length() - 1;
        int i = 0;
        while (i < size) {
            if (!isalnum((unsigned char)s[i])) {
                i++;
            } else if (!isalnum((unsigned char)s[size])) {
                size--;
            } else {
                if (tolower((unsigned char)s[i]) !=
                    tolower((unsigned char)s[size])) {
                    return false;
                }
                i++;
                size--;
            }
        }
return true;
    }
};