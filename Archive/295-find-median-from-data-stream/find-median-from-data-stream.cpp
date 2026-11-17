class MedianFinder {
public:

    priority_queue<int, vector<int>, greater<int> > left;
    priority_queue<int> right;

    MedianFinder() {
        while(!left.empty()){left.pop();}
        while(!right.empty()){right.pop();}
    }
    
    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();
        if(left.size()==right.size()){
            return;
        }
        left.push(right.top());
        right.pop();
    }
    
    double findMedian() {
        double ans;
        if(left.size()==right.size()){
            ans = (double)(left.top()+right.top())/2;
        }else{
            ans = left.top();
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */