class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        // Maximize
        string a = s;
        char x = '0';
        for (char c : a) {
            if (c != '9') {
                x = c;
                break;
            }
        }
        for (char &c : a) if (c == x) c = '9';

        // Minimize
        string b = s;
        if (b[0] != '1') {
            char x = b[0];
            for (char &c : b) if (c == x) c = '1';
        } else {
            char x = '0';
            for (int i = 1; i < b.size(); i++) {
                if (b[i] != '0' && b[i] != '1') {
                    x = b[i];
                    break;
                }
            }
            for (char &c : b) if (c == x) c = '0';
        }

        return stoi(a) - stoi(b);
    }
};
