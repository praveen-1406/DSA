class MyStack {
public:
    queue<int>st;
    // queue<int>aux;
    // int top;
    MyStack() {
        // top=-1;
    }
    
    void push(int x) {
        // if(st.empty())  st.push(x);
        // else{
        //     while(!st.empty()){
        //         aux.push(st.front());
        //         st.pop();
        //     }
        //     st.push(x);
        //     while(!aux.empty()){
        //         st.push(aux.front());
        //         aux.pop();
        //     }
        // }

        if(st.empty())  st.push(x);
        else{
            int size=st.size();
            st.push(x);
            while(size--){
                int a=st.front();
                st.pop();
                st.push(a);
            }
        }
    }
    
    int pop() {
        int x;
        if(!st.empty()){
            x=st.front();
            st.pop();
        }else   x=-1;
        return x;
    }
    
    int top() {
        if(!st.empty())    return st.front();
        else    return -1;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */