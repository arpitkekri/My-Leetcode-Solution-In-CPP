class MinStack {
public:
    long long minStk;
    stack<long long> stk;
    MinStack() {
        stk = stack<long long>();
    }
    
    void push(int val) {
        if(stk.empty()) {
            stk.push(val);
            minStk = val;
        }
        else {
            if(val >= minStk)
                stk.push(val);
            else {
                stk.push(2LL*val - minStk);
                minStk = val;
            }
        }
    }
    
    void pop() {
        if(stk.empty()) return;
        if(stk.top() >= minStk) stk.pop();
        else {
            minStk = 2*minStk - stk.top();
            stk.pop();
        }
    }
    
    int top() {
        if(stk.empty()) return -1;
        else {
            if(stk.top() >= minStk) 
                return stk.top();
            else return minStk;
        }
    }
    
    int getMin() {
        if(stk.empty()) return -1;
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