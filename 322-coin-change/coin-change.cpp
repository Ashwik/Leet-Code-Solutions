class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,INT_MAX));
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        
        for(int j=1;j<=amount;j++){
            for(int i=1;i<=n;i++){
                dp[i][j] = dp[i-1][j];
                if(j>=coins[i-1] && dp[i][j-coins[i-1]]!=INT_MAX){
                    dp[i][j] = min(dp[i][j], dp[i][j-coins[i-1]] + 1);
                }
            }
        }
        if(dp[n][amount]==INT_MAX){return -1;}
        return dp[n][amount];
    }
};