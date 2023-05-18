class Solution {
public:
    string reverseWords(string s) {
        
        reverse(s.begin(),s.end());

        string str = "";
        string ans = "";

        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(str!=""){
                    reverse(str.begin(),str.end());
                    ans += str + " ";
                }
                str = "";
            }else{
                str += s[i];
            }
        }

        if(str!=""){
             reverse(str.begin(),str.end());
             ans += str;
        }else{
            ans.erase(ans.begin()+ans.size()-1);
        }
        return ans;

    }
};