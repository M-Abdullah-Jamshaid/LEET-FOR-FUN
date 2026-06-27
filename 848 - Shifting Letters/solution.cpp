class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long currentShiftSum = 0;
        int n = s.size();

        for (int i = n - 1; i >= 0; i--) {
            currentShiftSum = (currentShiftSum + shifts[i]) % 26;

            int originalPos = s[i] - 'a';
            int newPos = (originalPos + currentShiftSum) % 26;
            
            s[i] = (char)(newPos + 'a');
        }

        return s;
    }
};