class MyQueue {
public:
    stack<int>input;
    stack<int>output;

    MyQueue() {
        
    }
    
    void push(int x) {
        // if(q.empty())   q.push(x);
        // else{
        //     while(!q.empty()){
        //         int a=q.top();
        //         q.pop();
        //         s.push(a);
        //     }
        //     q.push(x);
        //     while(!s.empty()){
        //         int a=s.top();
        //         s.pop();
        //         q.push(a);
        //     }
        // }
        input.push(x);
    }
    
    int pop() {
        int x=-1;
        // if(!q.empty()){
        //     x=q.top();
        //     q.pop();
        // }else   x=-1;
        // return x;
        if(output.empty()){
            while(!input.empty()){
                int a=input.top();
                output.push(a);
                input.pop();
            }
        }
        if(!output.empty()){
            x=output.top();
            output.pop();
        }
        
        return x;
    }
    
    int peek() {
        int x=-1;
        // if(!q.empty()){
        //     x=q.top();
        // }else   x=-1;
        // return x;
        if(output.empty()){
            while(!input.empty()){
                int a=input.top();
                output.push(a);
                input.pop();
            }
        }
        if(!output.empty()){
            x=output.top();
        }
        return x;
    }
    
    bool empty() {
        return input.empty() && output.empty() ;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */