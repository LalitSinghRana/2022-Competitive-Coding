class MyQueue {
private:
    stack<int> s;
public:
    MyQueue() {
        stack<int> t;
        s = t;
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        stack<int> t;
        
        while(!s.empty()) {
            t.push(s.top());
            s.pop();
        }
        
        int ans = t.top();
        t.pop();
        
        while(!t.empty()) {
            s.push(t.top());
            t.pop();
        }
        
        return ans;
    }
    
    int peek() {
        stack<int> t;
        
        while(!s.empty()) {
            t.push(s.top());
            s.pop();
        }
        
        int ans = t.top();
        
        while(!t.empty()) {
            s.push(t.top());
            t.pop();
        }
        
        return ans;
    }
    
    bool empty() {
        return s.empty();
    }
};
