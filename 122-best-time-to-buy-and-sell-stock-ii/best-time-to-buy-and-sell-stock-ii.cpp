class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int curmax = prices[n-1];
        int res = 0;
        for(int i=n-2;i>=0;i--){
            if(prices[i]<curmax){
                res += curmax-prices[i];
            }
            curmax = prices[i];
        }
        return res;
    }
};