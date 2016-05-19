class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int len = que.size();
        queue<int> temp;
        for(int i=0; i<len-1; i++)
        {
            temp.push(que.front());
            que.pop();
        }
        que.pop();
        que.swap(temp);
    }

    // Get the top element.
    int top() {
        return que.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
private:
    queue<int> que;
};