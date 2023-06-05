class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        int len=2;
        while(len<=n){
            string temp = ans;
            ans = "";
            int cnt = 1;
            int i;
            for(i=1;i<temp.length();i++){
                if(temp[i]==temp[i-1]){
                    cnt++;
                }else{
                    ans += to_string(cnt);
                    ans += temp[i-1];
                    cnt = 1;
                }
            }
            ans += to_string(cnt);
            ans += temp[i-1];
            len++;
        }
        return ans;

    }
};