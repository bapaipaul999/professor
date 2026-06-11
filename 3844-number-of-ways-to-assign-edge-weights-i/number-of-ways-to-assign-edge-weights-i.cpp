class Solution {
public:
    long long mod = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        for(int i = 0; i < b; i++) {
            ans = (ans * a) % mod;
        }

        return ans;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<int> q;
        vector<int> vis(n + 1, 0);

        q.push(1);
        vis[1] = 1;

        int depth = -1;

        while(!q.empty()) {

            int sz = q.size();
            depth++;

            while(sz--) {

                int node = q.front();
                q.pop();

                for(int nxt : adj[node]) {
                    if(!vis[nxt]) {
                        vis[nxt] = 1;
                        q.push(nxt);
                    }
                }
            }
        }

        if(depth == 0) {
            return 0;
        }

        return power(2, depth - 1);
    }
};