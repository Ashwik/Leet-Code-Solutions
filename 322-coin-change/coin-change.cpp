class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(2,vector<int>(amount+1,INT_MAX));
        for(int i=0;i<2;i++){
            dp[i][0] = 0;
        }
        
        for(int i=1;i<=n;i++){
            int cur = i%2;
            int prev = (i-1)%2;
            for(int j=1;j<=amount;j++){   
                dp[cur][j] = dp[prev][j];
                if(j>=coins[i-1] && dp[cur][j-coins[i-1]]!=INT_MAX){
                    dp[cur][j] = min(dp[cur][j], dp[cur][j-coins[i-1]] + 1);
                }
            }
        }
        if(dp[n%2][amount]==INT_MAX){return -1;}
        return dp[n%2][amount];
    }
};