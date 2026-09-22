class Solution {
    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int n, k;
    vector<Node> seg;

    Node merge(Node &a, Node &b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;

        for (int i = 0; i < k; i++) {
            res.cnt[i] = a.cnt[i];
        }

        for (int i = 0; i < k; i++) {
            int rem = (a.prod * i) % k;
            res.cnt[rem] += b.cnt[i];
        }

        return res;
    }

    void build(int p, int l, int r, vector<int>& nums) {
        if (l == r) {
            seg[p].prod = nums[l] % k;
            seg[p].cnt[nums[l] % k] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(p * 2, l, mid, nums);
        build(p * 2 + 1, mid + 1, r, nums);

        seg[p] = merge(seg[p * 2], seg[p * 2 + 1]);
    }

    void update(int p, int l, int r, int pos, int val) {
        if (l == r) {
            seg[p] = Node();
            seg[p].prod = val % k;
            seg[p].cnt[val % k] = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(p * 2, l, mid, pos, val);
        else
            update(p * 2 + 1, mid + 1, r, pos, val);

        seg[p] = merge(seg[p * 2], seg[p * 2 + 1]);
    }

    void query(int p, int l, int r, int ql, int qr, Node &ans) {
        if (ql <= l && r <= qr) {
            if (ans.prod == -1) {
                ans = seg[p];
            } else {
                ans = merge(ans, seg[p]);
            }
            return;
        }

        int mid = (l + r) / 2;

        if (ql <= mid)
            query(p * 2, l, mid, ql, qr, ans);

        if (qr > mid)
            query(p * 2 + 1, mid + 1, r, ql, qr, ans);
    }

public:
    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        this->k = k;
        n = nums.size();

        seg.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> ans;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value);

            Node res;
            res.prod = -1;

            query(1, 0, n - 1, start, n - 1, res);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};