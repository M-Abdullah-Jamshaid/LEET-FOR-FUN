class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int p1 = 0;
        int p2 = 0;
        int size1 = nums1.size();
        int size2 = nums2.size();
        while (p1 < size1 && p2 < size2) {
            if (nums1[p1] == nums2[p2]) {
                return nums1[p1];
            }

            if (nums1[p1] > nums2[p2]) {
                p2++;
            }
            else {
                p1++;
            }
        }

        return -1;
    }
};