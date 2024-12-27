class Solution {

    int findnextgreaterelement(int[] nums,int target){
        int st = 0,en=nums.length;
        int mid;
        while(st<en){
            mid = (st+en)/2;
            if(nums[mid]<=target){
                st = mid+1;
            }else{
                en = mid;
            }
        }
        return st;
    }

    public int[] searchRange(int[] nums, int target) {
        int lastindex = findnextgreaterelement(nums,target);
        int firstindex = findnextgreaterelement(nums,target-1);
        
        int[] ans = new int[2];
        if(lastindex==0 || nums[lastindex-1]!=target){
            ans[0]=-1;ans[1]=-1;
        }else{
            ans[0]=firstindex;
            ans[1]=lastindex-1;
        }
        return ans;
    }
}