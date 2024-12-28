class Solution {
    public int removeDuplicates(int[] nums) {
        int curnum = nums[0];
        int count = 1;
        int left=1,right=1;
        for(;right<nums.length;right++){
            if(nums[right]==curnum){
                count++;
            }else{
                curnum = nums[right];
                count = 1;
            }
            nums[left] = nums[right];

            if(count<=2){
                left++;
            }
        }
        return left;
    }
}