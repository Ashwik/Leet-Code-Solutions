class Solution {
public:

    int binarysearch(int st, int en, vector<int>& nums, int target){
        while(st<en){
            int mid = (st+en)/2;
            if(nums[mid]==target){return mid;}
            else if(nums[mid]>target){en=mid;}
            else{
                st = mid+1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0,en = n-1;
        int mid;

        while(st<en){
            mid = (st+en)/2;
            if(nums[mid]>nums[en]){
                st = mid+1;
            }else{
                en = mid;
            }
        }
        int rot = st;
        
        if(target==nums[n-1]){
            return n-1;
        }

        if(target<nums[n-1]){
            return binarysearch(rot,n,nums,target);
        }
        
        return binarysearch(0,rot,nums,target);

    }
};