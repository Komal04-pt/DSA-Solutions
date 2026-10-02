class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(minSt.empty() || value <= minSt.top())
            minSt.push(value);
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top() == minSt.top())
            minSt.pop();
            st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if(minSt.empty()) return -1;
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */