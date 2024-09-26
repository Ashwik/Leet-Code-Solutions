class StockSpanner {
public:
    vector<pair<int,int>> v;
    int curday;
    StockSpanner() {
        v.erase(v.begin(),v.end());
        curday = 0;
    }
    
    int next(int price) {
        curday++;
        while(v.size() > 0 && price >= v.back().first){
            v.pop_back();
        }
        if(v.size()==0){
            v.push_back({price,curday});
            return curday;
        }
        int ans = curday - v.back().second;
        v.push_back({price,curday});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */