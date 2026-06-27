#include <vector>

class Fancy {
private:
    std::vector<long long> seq;
    long long M = 1;
    long long A = 0;
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    Fancy() {}

    void append(int val) {
        long long invM = modInverse(M);
        long long baseVal = ((val - A + MOD) % MOD * invM) % MOD;
        seq.push_back(baseVal);
    }

    void addAll(int inc) {
        A = (A + inc) % MOD;
    }

    void multAll(int m) {
        M = (M * m) % MOD;
        A = (A * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= seq.size()) return -1;
        return (seq[idx] * M + A) % MOD;
    }
};