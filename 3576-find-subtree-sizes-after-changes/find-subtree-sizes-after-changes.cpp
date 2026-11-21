class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n), newAdj(n);

        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);

        vector<int> last(26, -1), newParent(n, -1);

        struct Event {
            int u, c, prev;
            bool exit;
        };

        vector<Event> st;
        st.push_back({0, s[0] - 'a', -1, false});

        while (!st.empty()) {
            auto e = st.back();
            st.pop_back();

            int u = e.u, c = e.c;

            if (e.exit) {
                last[c] = e.prev;
                continue;
            }

            int prev = last[c];

            if (u != 0)
                newParent[u] = (prev != -1 ? prev : parent[u]);

            last[c] = u;

            st.push_back({u, c, prev, true});

            for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];
                st.push_back({v, s[v] - 'a', -1, false});
            }
        }

        for (int i = 1; i < n; i++)
            newAdj[newParent[i]].push_back(i);

        vector<int> order;
        st.clear();
        st.push_back({0, 0, 0, false});

        while (!st.empty()) {
            int u = st.back().u;
            st.pop_back();

            order.push_back(u);

            for (int v : newAdj[u])
                st.push_back({v, 0, 0, false});
        }

        vector<int> ans(n, 1);

        for (int i = (int)order.size() - 1; i > 0; i--) {
            int u = order[i];
            ans[newParent[u]] += ans[u];
        }

        return ans;
    }
};