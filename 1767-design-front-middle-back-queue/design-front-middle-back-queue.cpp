class FrontMiddleBackQueue {
public:
    deque<int>dq;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        dq.push_front(val);
    }
    
    void pushMiddle(int val) {
        int n = dq.size();
        int idx = n/2;
        stack<int>s1;
        while(idx--){
            s1.push(dq.front());
            dq.pop_front();
        }
        dq.push_front(val);
        while(!s1.empty()){
            dq.push_front(s1.top());
            s1.pop();
        }
    }
    
    void pushBack(int val) {
        dq.push_back(val);
    }
    
    int popFront() {
        if(dq.empty()){
            return -1;
        }
        int x= dq.front();
        dq.pop_front();
        return x;
    }
    
    int popMiddle() {
        if(dq.empty()){
            return -1;
        }
        int n = dq.size();
        int idx = (n-1)/2;
        stack<int>s1;
        while(idx--){
            s1.push(dq.front());
            dq.pop_front();
        }
        int x = dq.front();
        dq.pop_front();
        while(!s1.empty()){
            dq.push_front(s1.top());
            s1.pop();
        }
        return x;

    }
    
    int popBack() {
        if(dq.empty()){
            return -1;
        }
        int x= dq.back();
        dq.pop_back();
        return x;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */