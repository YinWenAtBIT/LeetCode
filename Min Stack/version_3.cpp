class MinStack {
public:
    stack<int> stk;
    stack<int> min;
    
    void push(int x) {
        stk.push(x);
        if(min.empty() || x <= min.top())
            min.push(x);
    }

    void pop() {
        if(stk.top() == min.top())
        {
            stk.pop();
            min.pop();
        }
        else
            stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min.top();
    }
};