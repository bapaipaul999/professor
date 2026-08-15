class ATM {
public:
    vector<long long> temp = {0, 0, 0, 0, 0};
    vector<int> x = {20, 50, 100, 200, 500};

    ATM() {
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            temp[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> ans(5, 0);
        int remaining = amount;

        // Try larger denominations first
        for (int i = 4; i >= 0; i--) {
            long long take = min(
                temp[i],
                (long long)remaining / x[i]
            );

            ans[i] = take;
            remaining -= take * x[i];
        }

        // Cannot make exact amount
        if (remaining != 0) {
            return {-1};
        }

        // Transaction succeeded, update ATM
        for (int i = 0; i < 5; i++) {
            temp[i] -= ans[i];
        }

        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */