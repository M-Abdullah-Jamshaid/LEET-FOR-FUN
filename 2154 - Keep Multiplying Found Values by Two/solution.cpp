class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        long long i = 0;
        long long n = nums.size();
        while (i < n){
            if(nums[i]==original){
                original*=2;
            }
            i++;
        }
        return original;
    }
};