class Solution {
public:
    int strStr(string str, string s) {

        bool flag;
        for(int i=0;i<str.length();i++){
            if(str[i]==s[0]){
                flag = true;
                for(int j=1,k=i+1;j<s.length();j++,k++){
                    if(s[j]!=str[k]){
                        flag = false;break;
                    }
                }
                if(flag){return i;}
            }
        }
        return -1;
        
    }
};