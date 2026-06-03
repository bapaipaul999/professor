class Solution {
public:

    void dfs(int node,
             vector<int> adj[],
             vector<int>& visited) {

        visited[node] = 1;

        for (auto it : adj[node]) {

            if (visited[it] == 0) {
                dfs(it, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int size = isConnected.size();

        vector<int> adj[size];

        for (int i = 0; i < size; i++) {

            for (int j = 0; j < size; j++) {

                if (isConnected[i][j] == 1 &&
                    i != j) {

                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visited(size, 0);

        int count = 0;

        for (int i = 0; i < size; i++) {

            if (visited[i] == 0) {

                dfs(i, adj, visited);
                count++;
            }
        }

        return count;
    }
};