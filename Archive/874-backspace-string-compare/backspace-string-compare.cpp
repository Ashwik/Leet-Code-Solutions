class Solution {
public:

    void finalString(string &s)
    {
        int bs = 0;
        for(int i=s.length();i>=0;i--){
            if(s[i]=='#'){
                bs++;
            }else if(bs>0){
                s[i] = '#';
                bs--;
            }
        }
    }

    bool backspaceCompare(string s, string t) {
        
        
        finalString(s);
        finalString(t);

        int i=0,j=0;
        while(i<s.length() && j<t.length()){
            while(i<s.length() && s[i]=='#'){
                i++;
            }
            while(j<t.length() && t[j]=='#'){
                j++;
            }

            if(i==s.length()||j==t.length()){
                break;
            }

            if(s[i]!=t[j]){
                return false;
            }
            i++;j++;
        }
        
        while(i<s.length() && s[i]=='#'){
            i++;
        }
        while(j<t.length() && t[j]=='#'){
            j++;
        }

        if(i!=s.length() || j!=t.length()){
            return false;
        }

        return true;
    }
};