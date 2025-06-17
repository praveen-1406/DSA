class MinStack {
public:
    // stack<pair<int,int>>st;
    long mini;
    stack<long>st;
    MinStack() {
    }
    
    void push(int val) {
        // if(st.size()==0)    {
        //     st.push({val,val});
        // }else{
        //     st.push({val,min(val,st.top().second)});
        // }
        if(st.empty())  {
            st.push(val);
            mini=val;
        }else{
            if(val>mini){
                st.push(val);
            }else{
                long Val=val;
                st.push(2*Val-mini);
                mini=Val;
            }
        }
    }
    
    void pop() {
        // st.pop();
        long x=st.top();
        st.pop();
        if(x<mini){
            mini=2*mini-x;
        }
    }
    
    int top() {
        // return st.top().first;
        long x=st.top();
        if(x>mini)  return x;
        else    return mini;
    }
    
    int getMin() {
        // return st.top().second;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */