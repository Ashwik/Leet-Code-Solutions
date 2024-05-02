class Solution {
public:

    void computelpsarray(vector<int>& lps,string& s){
        int len=0,end=1;
        lps[len]=0;

        while(end<lps.size()){
            if(s[end]==s[len]){
                len++;
                lps[end]=len;
                end++;
            }else{
                if(len){
                    len = lps[len-1];
                }else{
                    lps[end]=0;
                    end++;
                }
            }
        }
    }

    int strStr(string str, string s) {

       
        if(s.length()==str.length()){
            if(s==str){return 0;}   
        }
        if(s.length()>=str.length()){return -1;}
        
        int n = str.length();//main string
        int m = s.length();//pattern
        vector<int> lps(m);
        computelpsarray(lps,s);
        int i=0,j=0;
        while(n-i>=m-j){
            if(str[i]==s[j]){
                i++;j++;
            }
            if(j==m){
                return i-j;
            }else if(i<n && str[i]!=s[j]){
                if(j==0){
                    i++;
                }else{
                    j = lps[j-1];
                }
            }
        }
        return -1;
        
    }
};