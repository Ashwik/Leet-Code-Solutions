class Solution {
public:

    int lower_bound(vector<int>& nums, int target){
        int st = 0 ,en = nums.size()-1;
        int mid;
        while(st<=en){
            mid = (st+en)/2;

            if(nums[mid]<target){
                st = mid+1;
            }else{
                en = mid-1;
            }
        }
        return st;
    }

    int upper_bound(vector<int>& nums, int target){
        int st = 0 ,en = nums.size()-1;
        int mid;
        while(st<=en){
            mid = (st+en)/2;

            if(nums[mid]<=target){
                st = mid+1;
            }else{
                en = mid-1;
            }
        }
        return en;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res(2,-1);
        int lowerInd = lower_bound(nums,target);
        int higherInd = upper_bound(nums,target);

        if(lowerInd < nums.size()&&target == nums[lowerInd]){
            res[0] = lowerInd;
            res[1] = higherInd;
        }
        return res;
    }
};