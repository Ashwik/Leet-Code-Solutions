class Solution {
    public int maxProduct(int[] nums) {
        
        int n = nums.length;
        int lowValue = nums[0];
        int highValue = nums[0];
        int ans = nums[0];

        for(int i=1;i<n;i++){
            if(nums[i]<0){
                int temp = lowValue;
                lowValue = highValue;
                highValue = temp;
            }
            lowValue = Math.min(nums[i],lowValue*nums[i]);
            highValue = Math.max(nums[i], highValue*nums[i]);
            ans = Math.max(ans,highValue);
        }
        return ans;
    }
}