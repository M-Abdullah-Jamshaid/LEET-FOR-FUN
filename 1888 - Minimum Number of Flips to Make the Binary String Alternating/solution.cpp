class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
    string doubled = s + s;
    
    int diff1 = 0, diff2 = 0;
    int ans = n; 
    for (int i = 0; i < doubled.length(); ++i) {
        char target1 = (i % 2 == 0) ? '0' : '1';
        char target2 = (i % 2 == 0) ? '1' : '0';

        if (doubled[i] != target1) diff1++;
        if (doubled[i] != target2) diff2++;

        if (i >= n) {
            char leftTarget1 = ((i - n) % 2 == 0) ? '0' : '1';
            char leftTarget2 = ((i - n) % 2 == 0) ? '1' : '0';

            if (doubled[i - n] != leftTarget1) diff1--;
            if (doubled[i - n] != leftTarget2) diff2--;
        }

        if (i >= n - 1) {
            ans = min({ans, diff1, diff2});
        }
    }

    return ans;
    }
};