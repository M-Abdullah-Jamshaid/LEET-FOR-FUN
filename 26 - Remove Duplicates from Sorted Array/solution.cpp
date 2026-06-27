class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> li;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            li[nums[i]]++;
        }
        nums.clear();
        int sizea=li.size();
        for(auto const&[a,b]:li ){
            nums.push_back(a);
        }
        return nums.size();
    }
};