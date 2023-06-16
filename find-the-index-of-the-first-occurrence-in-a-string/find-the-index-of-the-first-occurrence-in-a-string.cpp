class Solution {
public:
    int strStr(string str, string s) {

       
        if(s.length()==str.length()){
            if(s==str){return 0;}   
        }
         if(s.length()>=str.length()){return -1;}
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