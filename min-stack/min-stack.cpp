class MinStack {
public:
    long minStk;
    stack<long> stk;
    MinStack() {
        stk = stack<long>();
    }
    
    void push(int val) {
        if(stk.empty()) {
            stk.push(0L);
            minStk = val;
        }
        else {
            stk.push(val-minStk);
            if(val < minStk) minStk = val;
        }
    }
    
    void pop() {
        long ele = stk.top();
        stk.pop();
        if(ele < 0) minStk = minStk-ele;
    }
    
    int top() {
        long ele = stk.top();
        return ele > 0? ele+minStk: minStk;
    }
    
    int getMin() {
        return minStk;
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