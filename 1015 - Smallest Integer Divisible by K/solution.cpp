class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0||k%5==0) return -1;
        long long remainder=0;
        int length=0;
        for(int i=1;i<=k;++i){
            remainder=(remainder*10+1)%k;
            length++;
            if(remainder==0) return length;
        }
        return -1;
    }
};