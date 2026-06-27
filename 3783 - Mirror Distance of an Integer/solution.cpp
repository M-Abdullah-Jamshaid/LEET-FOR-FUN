class Solution {
public:
    int mirrorDistance(int n) {
        long long temp=0;
        long long a=n;
        while(n!=0)
        {
            int last=n%10;
            temp=temp*10+last;
            n=n/10;

        }
        return abs(a-temp);
        
    }
};