class Skiplist {
public:
    multiset<int> st;

    Skiplist() {
    }

    bool search(int target) {
        return st.find(target) != st.end();
    }

    void add(int num) {
        st.insert(num);
    }

    bool erase(int num) {
        auto it = st.find(num);

        if(it == st.end()) {
            return false;
        }

        st.erase(it);
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */