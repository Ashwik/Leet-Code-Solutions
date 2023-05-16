class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0,en=nums.size();
        int mid;

        while(st<en){
            mid = st + (en-st)/2;

            if((mid!=nums.size()-1 && mid%2==0 && nums[mid]==nums[mid+1])||(mid!=0 &&mid%2!=0 && nums[mid]==nums[mid-1])){
                st = mid+1;
            }else{
                en = mid;
            }

        }
        return nums[st];
    }
};