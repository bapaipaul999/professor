class NumberContainers {
public:
    map<int, int> mp; 
    map<int, priority_queue<int, vector<int>, greater<int>>> pq;

    NumberContainers() {
    }

    void change(int index, int number) {
        mp[index] = number;
        pq[number].push(index);
    }

    int find(int number) {
        if (pq.find(number) == pq.end()) {
            return -1;
        }

        auto &heap = pq[number];

        while (!heap.empty() && mp[heap.top()] != number) {
            heap.pop();
        }

        if (heap.empty()) {
            return -1;
        }

        return heap.top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */