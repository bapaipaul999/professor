class CustomStack {
public:
    deque<int>q1;
    int size ;
    CustomStack(int maxSize) {
        this -> size = maxSize;
    }
    
    void push(int x) {
        if(q1.size()<size){
            q1.push_back(x);
        }
    }
    
    int pop() {
        if(q1.empty()){
            return -1;
        }
        int x = q1.back();
        q1.pop_back();
        return x;
    }
    
    void increment(int k, int val) {
        stack<int>s1;
        for(int i = 0 ; i<k ; i++){
            if(q1.empty()){
                break;
            }
            s1.push(q1.front()+val);
            q1.pop_front();
        }
        while(!s1.empty()){
            q1.push_front(s1.top());
            s1.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */