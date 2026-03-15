class MedianFinder {
    // max-heap
    priority_queue<int>maxh;                            //strong smaller half
    // min-heap
    priority_queue<int,vector<int>,greater<int>>minh;   //storing larger half
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxh.push(num);
        minh.push(maxh.top());              //balancing
        maxh.pop(); 
        if(minh.size()>maxh.size()){        //rebalancing
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(minh.size()==maxh.size())    return (minh.top()+maxh.top())/2.0;     //even
        else    return maxh.top();                                              //odd
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */