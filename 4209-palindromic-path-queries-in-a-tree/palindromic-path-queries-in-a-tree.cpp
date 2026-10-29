
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> parent(n, -1), depth(n, 0);
        vector<int> tin(n), tout(n), sz(n, 1), order;
        vector<int> st = {0};
        parent[0] = 0;
        int timer = 0;

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();

            tin[u] = ++timer;
            order.push_back(u);

            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back(v);
            }
        }

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            sz[parent[u]] += sz[u];
        }

        for (int u = 0; u < n; u++)
            tout[u] = tin[u] + sz[u] - 1;

        for (int u = 0; u < n; u++)
            up[0][u] = parent[u];

        for (int k = 1; k < LOG; k++) {
            for (int u = 0; u < n; u++)
                up[k][u] = up[k - 1][up[k - 1][u]];
        }

        auto isAncestor = [&](int u, int v) {
            return tin[u] <= tin[v] && tout[v] <= tout[u];
        };

        auto lca = [&](int u, int v) {
            if (isAncestor(u, v)) return u;
            if (isAncestor(v, u)) return v;

            for (int k = LOG - 1; k >= 0; k--) {
                if (!isAncestor(up[k][u], v))
                    u = up[k][u];
            }
            return parent[u];
        };

        auto getMask = [](char c) {
            return 1 << (c - 'a');
        };

        vector<int> rootMask(n), euler(n + 1, 0);
        for (int u : order) {
            rootMask[u] = getMask(s[u]);
            if (u != 0)
                rootMask[u] ^= rootMask[parent[u]];

            euler[tin[u]] = rootMask[u];
        }

        vector<int> bit(n + 2, 0);

        auto add = [&](int i, int val) {
            while (i <= n) {
                bit[i] ^= val;
                i += i & -i;
            }
        };

        auto queryBit = [&](int i) {
            int res = 0;
            while (i > 0) {
                res ^= bit[i];
                i -= i & -i;
            }
            return res;
        };

        for (int i = 1; i <= n; i++)
            add(i, euler[i] ^ euler[i - 1]);

        vector<bool> ans;

        for (string& q : queries) {
            string type;
            int u;
            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int delta = getMask(s[u]) ^ getMask(c);
                add(tin[u], delta);
                add(tout[u] + 1, delta);
                s[u] = c;
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);
                int pathMask = queryBit(tin[u]) ^
                               queryBit(tin[v]) ^
                               getMask(s[w]);

                ans.push_back(pathMask == 0 ||
                              (pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};
