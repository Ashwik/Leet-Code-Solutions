class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                for(int k=j+1,l=n-1;k<l;){    
                    long long int sum = (long long int)nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(k<l  && nums[k]==nums[k+1]){
                            k++;
                        }
                        k++;
                    }else if(sum>target){
                        l--;
                    }else{
                        k++;
                    }
                    
                }
                while(j != n-2 && nums[j]==nums[j+1]){
                    j++;
                }
            }
            while(i != n-3 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return ans;
    }
};