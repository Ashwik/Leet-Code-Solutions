class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1,k=nums.size()-1;j<k;){
                sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1]){
                        j++;
                    }
                    j++;
                }else if(sum>0){
                    k--;
                }else{
                    j++;
                }
            }
            while(i<nums.size()-1 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return ans;
    }
};