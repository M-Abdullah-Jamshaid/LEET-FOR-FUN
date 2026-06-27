class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;

    for (int m = 2; m * m <= n; m++) {
        for (int r = 1; r < m; r++) {

            // primitive triple conditions
            if (((m - r) & 1) == 0) continue;     // same parity
            if (gcd(m, r) != 1) continue;

            int a = m*m - r*r;
            int b = 2*m*r;
            int c = m*m + r*r;

            if (c > n) break;

            // scale by k
            int k = 1;
            while (k * c <= n) {
                if (k * a <= n && k * b <= n)
                    cnt += 2;      // (a,b,c) and (b,a,c)
                k++;
            }
        }
    }
    return cnt;
    }
};