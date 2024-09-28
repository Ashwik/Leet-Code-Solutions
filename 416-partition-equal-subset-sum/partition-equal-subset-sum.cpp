class Solution {
public:

    bool dfs(vector<int>& nums,int ind, int sum, vector<vector<int>>& dp){

        if(nums.size()==ind){
            return false;
        }
        if(dp[ind][sum]!=-1){return dp[ind][sum];}

        if(sum-nums[ind]==0){
            dp[ind][sum] = 1;
            return true;
        }
        
        bool ans;
        ans =  dfs(nums,ind+1,sum,dp);
        if(sum-nums[ind]>0){
            ans = ans || dfs(nums,ind+1,sum-nums[ind],dp);
        }
        dp[ind][sum] = ans;
        return ans;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum = sum+nums[i];
        }
        if(sum%2!=0){return false;}
        sum = sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));

        return dfs(nums,0,sum,dp);
    }
};