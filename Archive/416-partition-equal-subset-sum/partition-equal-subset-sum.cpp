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
        int m = nums.size();
        for(int i=0;i<m;i++){
            sum = sum+nums[i];
        }
        if(sum%2!=0){return false;}
        sum = sum/2;
        vector<vector<bool>> dp(2,vector<bool>(sum+1,false));

        // for(int i=0;i<=m;i++){
        //     dp[i][0] = true;
        // }

        for(int i=1;i<=m;i++){
            int prev = (i-1)%2;
            int cur = i%2;
            dp[prev][0] = true;

            for(int j=1;j<=sum;j++){
                dp[cur][j] = dp[prev][j];
                if(j>=nums[i-1] && dp[prev][j-nums[i-1]]){
                    dp[cur][j] = true;
                }
            }
            //if(dp[i][sum]==true){return true;}
        }
        return dp[m%2][sum];
        // return dfs(nums,0,sum,dp);
    }
};