class Solution {
public:


    bool wordBreak(string s, vector<string>& word) {
        
        int n = s.length();
        unordered_set<string> wordset;
        for(int i=0;i<word.size();i++){
            wordset.insert(word[i]);
        }
        if(wordset.count(s)){return true;}

        vector<bool> dp(n+1,false);
        
        dp[0] = true;

        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j] && wordset.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
        
    }
};