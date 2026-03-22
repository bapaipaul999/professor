class MyStack {
    queue<int> q1, q2;

public:
    MyStack() {}

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        if (q1.empty()) return -1;

        int n = q1.size();
        while (n > 1) {
            q2.push(q1.front());
            q1.pop();
            n--;
        }

        int x = q1.front();
        q1.pop();

        swap(q1, q2);
        return x;
    }

    int top() {
        if (q1.empty()) return -1; 

        int n = q1.size();
        while (n > 1) {
            q2.push(q1.front());
            q1.pop();
            n--;
        }

        int x = q1.front();

        
        q2.push(x);
        q1.pop();

        swap(q1, q2);
        return x;
    }

    bool empty() {
        return q1.empty();
    }
};