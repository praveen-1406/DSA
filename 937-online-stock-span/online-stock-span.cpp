class StockSpanner {
public:
    vector<int>stock;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=0;
        stock.push_back(price);
        for(int i=stock.size()-1;i>=0;i--){
            if(stock[i]<=price) span++;
            else break;
        }
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */