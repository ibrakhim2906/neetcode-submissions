class MinStack {
private:
    stack<int> stck{};
    stack<int> minStck{};
public:
    MinStack() {
    }
    
    void push(int val) {
        stck.push(val);

        val = min(val, minStck.empty() ? val : minStck.top());

        minStck.push(val);
        
    }
    
    void pop() {
        stck.pop();
        minStck.pop();
    }
    
    int top() {
        return stck.top();
        
    }
    
    int getMin() {
        return minStck.top();
        
    }
};
