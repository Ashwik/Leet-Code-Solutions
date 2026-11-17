class Solution {
public:

    void findnextgreatestelement(vector<int>& arr, int target){
        int st=0,en=arr.size();
        int mid;
        while(st<en){
            mid = (st+en)/2;
            if(arr[mid]==target){return;}
            else if(arr[mid]<target){
                st = mid+1;
            }else{
                en = mid;
            }
        }
        arr[st] = target;return;
    }


    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        v.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            if(nums[i]>v.back()){
              v.push_back(nums[i]);  
            }else{
              findnextgreatestelement(v, nums[i]);
            }
        }
        return v.size();
    }
};