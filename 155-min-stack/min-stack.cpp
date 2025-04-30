class MinStack {
public:
        // Idea is to modify the value being replaced as the min value of the stack
        // new_val = 2*val_to_insert - curr_min
        // push new_val into stack and val_to_insert as new minimum
    stack<long long> st;
    long long minVal;

    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty())
        {
            minVal = val;
            st.push(val);
        }
        else if(val > minVal)
        {
            st.push(val);
        }
        else // val < minVal - do modification here as per the formula
        {
            // basically trying to do 2*val - minVal here, but avoiding overflow
            long long int x = val;
            x = x * 2;
            x = x - minVal;
            st.push(x);
            minVal = val;
        }
    }
    
    void pop() {
        // this condition being true means that this value is indeed modified one
        // above fact can be verified from striver's video where we make
        // 2*val - minVal < val
        // new_val < val -> this relation proves that value at top, if less than minVal, was surely modified
        if(st.top() < minVal) 
        {
            // we need to get the previous minVal now, hence using the same formula, trying to find minVal
            // with val as minVal since that was the element originally had to be inserted but got modified
            minVal = 2*minVal - st.top();
            st.pop();
        }
        else
        {
            st.pop();
        }
    }
    
    int top() {
        // again same thing, get the original value (which is minVal) and not the modified one
        if(st.top() < minVal) 
        {
           return minVal;
        }
        else
        {
            return st.top();
        }
    }
    
    int getMin() {
        return minVal;
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