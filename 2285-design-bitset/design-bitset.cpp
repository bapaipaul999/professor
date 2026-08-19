class Bitset {
public:
    vector<int> s;
    bool flipped = false;
    int ones = 0;
    int n;

    Bitset(int size) {
        n = size;
        s.resize(n, 0);
    }
    
    void fix(int idx) {
        int actual = s[idx];

        if (flipped)
            actual = 1 - actual;

        if (actual == 0) {
            ones++;
            s[idx] = flipped ? 0 : 1;
        }
    }
    
    void unfix(int idx) {
        int actual = s[idx];

        if (flipped)
            actual = 1 - actual;

        if (actual == 1) {
            ones--;
            s[idx] = flipped ? 1 : 0;
        }
    }
    
    void flip() {
        flipped = !flipped;
        ones = n - ones;
    }
    
    bool all() {
        return ones == n;
    }
    
    bool one() {
        return ones > 0;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        string ans = "";

        for (int i = 0; i < n; i++) {
            int bit = s[i];

            if (flipped)
                bit = 1 - bit;

            ans += char('0' + bit);
        }

        return ans;
    }
};
/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */