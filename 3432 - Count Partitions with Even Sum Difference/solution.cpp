class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int odds=0;
        int ss=nums.size();
        for(int n:nums){
            if(n&1){
                odds++;
            }
        }
        if(odds%2==0){
         return ss-1;
        }
        else{
            return 0;
        }
    }
};