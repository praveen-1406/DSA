class StockSpanner {
public:
    // vector<int>stock;
    stack<pair<int,int>>st;
    int ind=-1;
    StockSpanner() {
        ind=-1;
        // st.clear();
    }
    
    int next(int price) {
        // int span=0;
        // stock.push_back(price);
        // for(int i=stock.size()-1;i>=0;i--){
        //     if(stock[i]<=price) span++;
        //     else break;
        // }
        // return span;
        ind++;
        while(!st.empty() && st.top().first<=price)     st.pop();
        int span=ind-((st.empty())?-1:st.top().second);
        st.push({price,ind});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */