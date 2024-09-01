class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int lowVal = res;
        int highVal = res; 
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                int temp = lowVal;
                lowVal = highVal;
                highVal = temp;
            }
            lowVal = min(lowVal*nums[i], nums[i]);
            highVal = max(highVal*nums[i], nums[i]);
            res = max(res,highVal);
        }
        return res;
    }
};