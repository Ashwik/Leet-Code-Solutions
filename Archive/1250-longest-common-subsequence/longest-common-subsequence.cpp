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
        
        
        
        int m = text1.length();
        int n = text2.length();

        if(m<n){return longestCommonSubsequence(text2, text1);}

        vector<vector<int>> dp(2, vector<int>(n+1,0));

        for(int i=1;i<=text1.length();i++){
            int curind  = i%2;
            int prevind = (i-1)%2;
            for(int j=1;j<=text2.length();j++){     
                if(text1[i-1]==text2[j-1]){
                    dp[curind][j] = 1 + dp[prevind][j-1];
                }else{
                    dp[curind][j] = max(dp[prevind][j], dp[curind][j-1]);
                }
            }
        }
        return dp[m%2][n];
        
    }
};