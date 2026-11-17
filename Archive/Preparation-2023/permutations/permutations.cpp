class Solution {
public:

    void permutations(vector<vector<int>>& ans,int ind,vector<int>&nums){

        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=ind;i<nums.size();i++){
            if(i==ind){permutations(ans,ind+1,nums);continue;}
            swap(nums[i],nums[ind]);
            permutations(ans,ind+1,nums);
            swap(nums[i],nums[ind]);
        }

    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(ans,0,nums);
        return ans;
    }
};