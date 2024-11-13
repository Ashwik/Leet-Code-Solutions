class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());

        int j = 0;
        int num = 0;
        for(int i=0;i<g.size();i++){
            while(j<s.size()){
                if(s[j]>=g[i]){
                    num++;
                    j++;
                    break;
                }
                j++;
            }
            if(j>=s.size()){return num;}
        }
        return num;
    }
};