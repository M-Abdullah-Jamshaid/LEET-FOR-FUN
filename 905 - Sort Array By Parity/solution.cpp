class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int end = nums.size()-1;
        int st = 0;
        while (st < end) {
            if (nums[st] % 2 != 0) {
                int temp=nums[st];
                 nums[st]=nums[end];
                 nums[end]=temp;
                end--;
            }else{
                st++;

            }
        }
        return nums;
    }
};