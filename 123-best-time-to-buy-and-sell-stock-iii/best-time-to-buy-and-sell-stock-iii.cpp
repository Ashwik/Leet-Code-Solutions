class Solution {
public:


    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int t[n+1][3][2];
        for(int i=0;i<=2;i++){
            t[0][i][0] = 0;
            t[0][i][1] = INT_MIN;   
        }
        
        
        for(int i=1;i<=n;i++){
                t[i][2][0] = max(t[i-1][2][0], t[i-1][2][1]+prices[i-1]);
                t[i][2][1] = max(t[i-1][2][1], t[i-1][1][0]-prices[i-1]);
                t[i][1][0] = max(t[i-1][1][0], t[i-1][1][1]+prices[i-1]);
                t[i][1][1] = max(t[i-1][1][1], -prices[i-1]);
        }
        return t[n][2][0];
    }
};