class Solution {
public:


    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int st = 0 , en = n-1;

        while(st<en){
            int mid = (st+en)/2;
            if(mid==0 || mid==n-1){return nums[mid];}
            if(mid%2==0){
                if(nums[mid]==nums[mid-1]){
                    en = mid-1;
                }else if(nums[mid]==nums[mid+1]){
                    st = mid+1;
                }else{
                    return nums[mid];
                }
            }else{
                if(nums[mid]==nums[mid+1]){
                    en = mid-1;
                }else if(nums[mid]==nums[mid-1]){
                    st = mid+1;
                }else{
                    return nums[mid];
                }
            }
        }
        return nums[st];
    }
};