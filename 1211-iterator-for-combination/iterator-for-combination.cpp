class CombinationIterator {
public:
    vector<string> ans;
    int idx = 0;

    void f(int start, string temp, string &characters, int k) {
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < characters.size(); i++) {
            temp.push_back(characters[i]);
            f(i + 1, temp, characters, k);
            temp.pop_back();
        }
    }

    CombinationIterator(string characters, int combinationLength) {
        f(0, "", characters, combinationLength);
    }

    string next() {
        return ans[idx++];
    }

    bool hasNext() {
        return idx < ans.size();
    }
};