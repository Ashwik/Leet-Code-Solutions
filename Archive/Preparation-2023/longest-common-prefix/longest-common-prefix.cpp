class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i=0;i<strs[0].length();i++){
            char ch = strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(i>strs[j].length()){return ans;}
                if(strs[j][i]!=ch){
                    return ans;
                }
            }
            ans += strs[0][i];
        }

        return ans;

    }
};