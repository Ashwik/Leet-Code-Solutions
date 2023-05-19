class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<int> st;
    stack<int> num;
    int ind = 1;
    
    int next(int price) {
        while(!st.empty() && price >= st.top()){
            st.pop();
            num.pop();
        }
        int res;
        if(st.empty()){
            res = ind;
        }else{
            res = ind-num.top();
        }
        st.push(price);
        num.push(ind);
        ind++;
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */