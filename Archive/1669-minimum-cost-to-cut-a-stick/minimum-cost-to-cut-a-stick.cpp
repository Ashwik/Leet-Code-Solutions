class Solution {
public:

    int dp[102][102];

    int findsol(vector<int>& cuts,int st, int en){
        
        if(st>=en-1){return 0;}
        if(dp[st][en]!=NULL){return dp[st][en];}
        int n  = cuts[en]-cuts[st];
        int ans = INT_MAX/2;
        for(int i=st+1;i<en;i++){
            ans = min(ans, n + findsol(cuts,st,i)+findsol(cuts,i,en));
        }
        dp[st][en] = ans;
        return ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return findsol(cuts,0,cuts.size()-1);
    }
};