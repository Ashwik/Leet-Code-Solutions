class Solution {
public:


    int partition(vector<int>& nums,int st,int en){
        int pivot = nums[st];
        int low=st+1,high=en;

        while(low<=high){
            if(nums[low]>pivot && nums[high]<pivot){
                swap(nums[low++],nums[high--]);
            }
            if(nums[low]<=pivot){
                low++;
            }
            if(nums[high]>=pivot){
                high--;
            }
        }
        swap(nums[high],nums[st]);
        return high;
    }


    int findKthLargest(vector<int>& nums, int k) {
       
        int n = nums.size();
        int st = 0,en = n-1;
        int ind = 0;
        while(true){
            ind = partition(nums,st,en);
            if(ind==n-k){break;}
            if(ind>n-k){
                en = ind-1;
            }else{
                st = ind+1;
            }
        }

        return nums[ind];
    }
};