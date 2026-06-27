class Solution {
public:
    int reverse(int x) {

        long long temp = x;
        long dig = 0;
        long long rev = 0;
        bool c = false;
        if (x < 0) {
            temp = abs(temp);
            c = true;
        }

        while (temp != 0) {

            dig = temp % 10;
            temp /= 10;
            rev = (rev * 10) + dig;
        }

        if(rev>INT_MAX){
            return 0;
        }
        if (c) {
            return -1*rev;
        } else
            return rev;
    }
};