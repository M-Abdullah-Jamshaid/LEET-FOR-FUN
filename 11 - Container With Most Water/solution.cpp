class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0,right = n-1;
        long long maxi = 0;
        while(left<right){
            long long current = min(height[left],height[right])*(right-left);
            maxi = max(maxi,current);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxi;
    }
};