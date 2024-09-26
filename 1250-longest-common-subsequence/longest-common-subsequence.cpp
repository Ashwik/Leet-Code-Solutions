class Solution {
public:

    int findlongest(string text1, int ind1, string text2, int ind2, vector<vector<int>> dp){
        
        if(ind1==text1.length() || ind2 == text2.length()){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        int ans = 0;
        if(text1[ind1] == text2[ind2]){
            ans = 1 + findlongest(text1,ind1+1,text2,ind2+1,dp);
        }else{
            ans = max(findlongest(text1,ind1+1,text2,ind2,dp), findlongest(text1,ind1,text2,ind2+1,dp));
        }

        dp[ind1][ind2] = ans;
        return ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1,0));

        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
            }
        }
        return dp[text1.length()][text2.length()];
        
    }
};