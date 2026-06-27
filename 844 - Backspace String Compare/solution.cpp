class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        int size_s = s.size();
        int i = 0;
        for (int i = 0; i < size_s; i++) {
            if ((s[i] == '#')) {
                if (!s1.empty()) {
                    s1.pop();
                }

            } else {
                s1.push(s[i]);
            }
        }

        stack<char> t1;
        int size_t1 = t.size();

        for (int i = 0; i < size_t1; i++) {
            if ( (t[i] == '#')) {
                if(!t1.empty()){
                    
                t1.pop();
                }

            } else {
                t1.push(t[i]);
            }
        }

        if (t1.size() != s1.size()) {
            return false;
        }
        int size1 = t1.size();

        for (int i = 0; i < size1; i++) {
            if (s1.top() == t1.top()) {
                s1.pop();
                t1.pop();

            } else {
                return false;
            }
        }

        return true;
    }
};