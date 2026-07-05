class MinStack {
public:
    
    stack<pair<int,int>>s1;
    MinStack() {
        
    }
    
    void push(int value) {
        if(s1.empty()){
            s1.push({value , value});

        }
        else{
            auto [x,y] = s1.top();
            s1.push({value , min(value , y)});
        }
    }
    
    void pop() {
        s1.pop();

    }
    
    int top() {
        auto [x,y] = s1.top();
        return x;
    }
    
    int getMin() {
       auto [x,y] = s1.top();
        return y;
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