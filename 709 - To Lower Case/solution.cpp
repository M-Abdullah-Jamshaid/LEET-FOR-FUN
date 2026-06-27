class Solution {
public:
    string toLowerCase(string s) {
        string ans;
        for(int i=0;i<s.size();i++)
        {
            char c = s[i];
             if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
            }
            ans += c; 
        }
        return ans;
    }
//please upvote...
};