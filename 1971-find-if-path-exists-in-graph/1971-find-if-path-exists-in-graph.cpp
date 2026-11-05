class Solution {
public:
    bool dfs(int src, int dest, vector<vector<int>>& adj,
             vector<bool>& vis) {

        if (src == dest) {
            return true;
        }

        vis[src] = true;

        for (int v : adj[src]) {
            if (!vis[v]) {
                if (dfs(v, dest, adj, vis)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        // Build adjacency list
        vector<vector<int>> adj(n);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);

        return dfs(source, destination, adj, vis);
    }
};

