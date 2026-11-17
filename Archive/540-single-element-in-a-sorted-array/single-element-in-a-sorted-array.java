class Solution {

    public int singleNonDuplicate(int[] nums) {
        if(nums.length==1){
            return nums[0];
        }
        int st = 0,en=nums.length-1;
        int mid;
        while(st<en){
            mid = (st+en)/2;

            if(mid==0 || mid==nums.length-1){
                return nums[mid];
            }else{
                if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                    return nums[mid];
                }

                if(mid%2==0){
                    if(nums[mid]==nums[mid-1]){
                        en = mid-1;
                    }else{
                        st = mid+1;
                    }
                }else{
                    if(nums[mid]==nums[mid-1]){
                        st = mid+1;
                    }else{
                        en = mid-1;
                    }
                }
            }
        }
        return nums[st];
    }
}