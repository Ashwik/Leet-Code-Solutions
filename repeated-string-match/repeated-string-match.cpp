class Solution {
public:

    void computelpsarray(vector<int>& lps, string& st){
            int len = 0;
            int en = 1;
            lps[len] = 0;

            while(en<st.length()){

                if(st[len]==st[en]){
                    len++;
                    lps[en] = len;
                    en++;
                }else{
                    if(len!=0){
                        len = lps[len-1];
                    }else{
                        lps[en]=0;
                        en++;
                    }
                }

            }

    }

    bool patternmatching(string& main, string& pat, vector<int>& lps){

        int i=0,j=0;

        while(main.length()-i >= pat.length()-j){

            if(main[i]==pat[j]){
                i++;j++;
            }
            if(j==pat.length()){
                return true;
            }else if(i<main.length() && main[i] != pat[j]){
                if(j!=0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return false;

    }

    int repeatedStringMatch(string s1, string s2) {
        
        if(s2.length()==0){return true;}


        string str = s1;
        int n = 1;
        while(str.length()<s2.length()){
            str += s1;
            n++;
        }

        vector<int> lps(s2.length());
        computelpsarray(lps,s2);

        bool a = patternmatching(str,s2,lps);
        if(a){return n;}
        str += s1;
        a = patternmatching(str,s2,lps);
        if(a){return n+1;}

        return -1;

    }
};