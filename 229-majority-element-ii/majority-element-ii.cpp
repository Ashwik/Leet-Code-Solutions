class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int count1=1,count2=0,num1=nums[0],num2=nums[0];

        for(int i=1;i<nums.size();i++){

            if(nums[i]==num1){
                count1++;
            }
            else if(nums[i]==num2){
                count2++;
            }
            else if(count1==0){
                num1 = nums[i];
                count1++;
            }
            else if(count2==0){
                num2 = nums[i];
                count2++;
            }
            else{
                count1--;count2--;
            }
        }
        count1=0;count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num1){
                count1++;
            }else if(nums[i]==num2){
                count2++;
            }
        }
        vector<int> res;
        int k = nums.size()/3;
        if(count1>k){
            res.push_back(num1);
        }
        if(count2>k){
            res.push_back(num2);
        }
        return res;
    }
};