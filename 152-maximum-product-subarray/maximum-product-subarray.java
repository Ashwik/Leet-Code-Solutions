class Solution {
    public int maxProduct(int[] nums) {
        int ans = Integer.MIN_VALUE;
        int product = 1;
        int n = nums.length;
        for(int i=0;i<n;i++){
            product = product*nums[i];
            ans = Math.max(product,ans);
            if(product==0){
                product=1;
            }
        }
        product=1;
        for(int i=n-1;i>=0;i--){
            product = product*nums[i];
            ans = Math.max(product,ans);
            if(product==0){
                product=1;
            }
        }
        return ans;
    }
}