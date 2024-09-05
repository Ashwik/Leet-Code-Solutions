class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int num = 1;
        int j=1;

        for(int i=1;i<nums.size();i++,j++){

            if(num==2){
                while(i < nums.size() && nums[i]==nums[i-1]){
                    i++;
                }
                num = 1;
                if(i==nums.size()){
                    break;
                }
            }

            if(nums[i]==nums[i-1]){
                num++;
            }
            nums[j] = nums[i];
        }
        return j;
    }
};