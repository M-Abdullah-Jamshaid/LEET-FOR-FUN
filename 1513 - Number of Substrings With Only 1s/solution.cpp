class Solution {
public:
    int numSub(string s) {
    const long long MOD = 1000000007;
    long long ans = 0;
    long long c = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            c = c + 1;
        } else {
            long long temp = c * (c + 1) / 2;
            temp = temp % MOD;
            ans = (ans + temp) % MOD;
            c = 0;
        }
    }

    long long temp = c * (c + 1) / 2;
    temp = temp % MOD;
    ans = (ans + temp) % MOD;

    return (int)ans;
    }
};