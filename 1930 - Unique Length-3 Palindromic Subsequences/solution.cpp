class Solution {
public:
    int countPalindromicSubsequence(string s) {
        std::vector<int> first(26, -1);
        std::vector<int> last(26, -1);
        
        // Step 1: Record first and last occurrence of each character
        for (int i = 0; i < s.length(); ++i) {
            int charIndex = s[i] - 'a';
            if (first[charIndex] == -1) {
                first[charIndex] = i;
            }
            last[charIndex] = i;
        }
        
        int answer = 0;
        
        // Step 2: Iterate through all 26 characters to see if they can be the outer shell 'X...X'
        for (int i = 0; i < 26; ++i) {
            // We need a valid range where start < end
            if (first[i] != -1 && last[i] != -1 && first[i] < last[i]) {
                std::unordered_set<char> uniqueCharsBetween;
                
                // Step 3: Check unique characters strictly between first and last occurrence
                for (int k = first[i] + 1; k < last[i]; ++k) {
                    uniqueCharsBetween.insert(s[k]);
                }
                
                answer += uniqueCharsBetween.size();
            }
        }
        
        return answer;
    }
};