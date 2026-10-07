class Solution {
public:

    void bfs(vector<vector<int>>& adj, vector<bool>& visit,
             int node, int& nodes, int& edges) {

        queue<int> q;
        q.push(node);
        visit[node] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            nodes++;
            edges += adj[curr].size();

            for (int nei : adj[curr]) {
                if (!visit[nei]) {
                    visit[nei] = true;
                    q.push(nei);
                }
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for (int node = 0; node < n; node++) {
            if (!visit[node]) {
                int nodes = 0;
                int edgeCount = 0;

                bfs(adj, visit, node, nodes, edgeCount);
                edgeCount /= 2;
                int requiredEdges = nodes * (nodes - 1) / 2;

                if (edgeCount == requiredEdges) {
                    res++;
                }
            }
        }
        return res;
    }
};