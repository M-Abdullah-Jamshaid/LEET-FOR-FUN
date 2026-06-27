class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int s=nums.size(),ind=0,count=0;
        bool check=true;


        for(int i=0;i<s;i++){

            if(count!=0){
                if(nums[i]==1){
                    if(i-ind<=k)check=false;
                }
            }
            if( nums[i]==1){
               ind=i;
               count++;
            }
            
        }
    return check;
    }
};