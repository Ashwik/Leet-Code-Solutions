class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k==0){return 0;}

        int res = 0;
        int prod = 1;
        for(int i=0,j=0;i<nums.size();i++){
            prod = prod*nums[i];
            while(j<=i && prod>=k){
                prod = prod/nums[j];j++;
            }
            res += (i-j+1);
        }
        return res;
    }
};