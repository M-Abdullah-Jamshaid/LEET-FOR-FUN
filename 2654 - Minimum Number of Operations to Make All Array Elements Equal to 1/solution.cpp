class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),no_o=0;
        bool found = false;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                found = true;
                no_o++;
            }
        }
        if(found) return n - no_o;
        int len=n;
        for(int i=0;i<n-1;i++){
            int cd = nums[i];
            for(int j=i+1;j<n;j++){
                if(gcd(cd,nums[j])==1){
                    found=true;
                    len = min(len,j-i+1);
                    break;
                }
                cd = gcd(cd,nums[j]);
            }
        }
        if(found) return (len-1)+n-1;
        return -1;
    }
};