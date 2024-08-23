class Solution {
public:

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.length()>s.length()){
            return ans;
        }
        vector<int> v(26,0);
        for(int i=0;i<p.length();i++){
            v[p[i]-'a']--;
        }
        bool flag;

        for(int i=0,j=0;i<s.length();i++){
            flag = true;  
            v[s[i]-'a']++;
            if(i>=p.length()-1){
                for(int k=0;k<26;k++){
                    if(v[k]!=0){
                        flag = false;break;
                    }
                }
                if(flag){
                    ans.push_back(j);
                }
                v[s[j]-'a']--;
                j++;
            }
        }

        return ans;
    }
};