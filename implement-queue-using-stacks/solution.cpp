class MyQueue {
private:
    stack<int> input;   // For push operations
    stack<int> output;  // For pop/peek operations
    
public:
    MyQueue() {
        // Constructor - stacks are empty by default
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        // If output is empty, transfer all elements from input
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        
        int front = output.top();
        output.pop();
        return front;
    }
    
    int peek() {
        // If output is empty, transfer all elements from input
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};