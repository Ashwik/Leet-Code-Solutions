class MedianFinder {
public:

    priority_queue<int,vector<int>,greater<int>> large;
    priority_queue<int> small;

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        large.push(num);
        small.push(large.top());
        large.pop();

        if(small.size()>large.size()){
            large.push(small.top());
            small.pop();
        }
        
    }
    
    double findMedian() {
        if(large.size()>small.size()){
            return (double)large.top();
        }

        return (double)(large.top()+small.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */