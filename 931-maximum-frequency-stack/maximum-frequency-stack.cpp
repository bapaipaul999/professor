class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int, stack<int>> group;
    int maxFreq = 0;

    FreqStack() {}

    void push(int val) {
        freq[val]++;
        maxFreq = max(maxFreq, freq[val]);
        group[freq[val]].push(val);
    }

    int pop() {
        int x = group[maxFreq].top();
        group[maxFreq].pop();

        freq[x]--;

        if(group[maxFreq].empty()) {
            maxFreq--;
        }

        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */