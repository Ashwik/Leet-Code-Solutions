class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>> st;
    int ind = 1;
    
    int next(int price) {
        while(!st.empty() && price >= st.top().first){
            st.pop();
        }
        int res;
        if(st.empty()){
            res = ind;
        }else{
            res = ind-st.top().second;
        }
        st.push({price,ind});
        ind++;
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */