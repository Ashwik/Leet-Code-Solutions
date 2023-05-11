class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        random_shuffle(std::begin(nums),std::end(nums));
        int st=0,en=nums.size()-1;
        int n = nums.size();
        int ind = 0;
        while(true){
            ind = findpartition(nums,st,en);
            if(ind==n-k){break;}
            else if(ind>n-k){
                en = ind-1;
            }else{
                st = ind+1;
            }
        }
        return nums[ind];
        
    }


    int findpartition(vector<int>&nums,int left,int right){
        int pivot =nums[left];
        int l = left+1;
        int r = right;

        while(l<=r){
            if(nums[l]>pivot && nums[r]<pivot){
                swap(nums[l++],nums[r--]);
            }
            if(nums[l]<=pivot){
                l++;
            }
            if(nums[r]>=pivot){
                r--;
            }
        }
        swap(nums[left],nums[r]);
        return r;
    }
};