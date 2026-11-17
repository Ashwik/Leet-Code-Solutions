class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = nums.size();
        int sum = 0;
        bool flag = false;
        for(int i=0,j=0;i<nums.size();i++){
            sum += nums[i];
            while(sum>=target && j<=i){
                flag = true;
                res = min(res,i-j+1);
                sum = sum-nums[j];
                j++;
            }
        }
        if(flag==false){return 0;}
        return res;
    }
};