class Solution {
public:

    bool dfs(string& s, int ind, string& curstr, unordered_set<string>& word, vector<vector<int>> &dp){
        if(ind==s.length()){
            if(word.count(curstr)){return true;}
            return false;
        }
        if(dp[ind][curstr.length()]!=-1){
            return dp[ind][curstr.length()];
        }
        bool ans = false;
        string newstr = curstr;
        if(word.count(curstr)){
            newstr = s[ind];
            ans = dfs(s,ind+1,newstr,word,dp);
        }
        if(ans){
            dp[ind][0] = true;
            return true;
        }
        newstr = curstr + s[ind];
        ans = dfs(s,ind+1,newstr,word,dp);
        dp[ind][curstr.length()] = ans;
        return ans;
    }

    bool wordBreak(string s, vector<string>& word) {
        unordered_set<string> st;
        for(int i=0;i<word.size();i++){
            st.insert(word[i]);
        }
        vector<vector<int>> dp(s.length(),vector<int>(s.length()+1,-1));
        string curstr = "";
        return dfs(s,0,curstr,st,dp);
    }
};