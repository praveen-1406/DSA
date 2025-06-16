class MyQueue {
public:
    stack<int>q;
    stack<int>s;

    MyQueue() {
        
    }
    
    void push(int x) {
        if(q.empty())   q.push(x);
        else{
            while(!q.empty()){
                int a=q.top();
                q.pop();
                s.push(a);
            }
            q.push(x);
            while(!s.empty()){
                int a=s.top();
                s.pop();
                q.push(a);
            }
        }
    }
    
    int pop() {
        int x;
        if(!q.empty()){
            x=q.top();
            q.pop();
        }else   x=-1;
        return x;
    }
    
    int peek() {
        int x;
        if(!q.empty()){
            x=q.top();
        }else   x=-1;
        return x;
    }
    
    bool empty() {
        return q.empty();
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