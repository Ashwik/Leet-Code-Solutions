class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0){return 0;}
        int res = nums[0], sum = 0;

        for(int i=0;i<nums.size();i++){
            sum = sum+nums[i];
            res = max(res,sum);
            if(sum<0){sum = 0;}
        }
        return res;
    }
};