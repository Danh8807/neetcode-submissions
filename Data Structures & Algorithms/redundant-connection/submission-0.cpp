class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;
    int cycleStart;
    unordered_set<int> cycle;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adj.resize(n+1);
        
        for(int i = 0; i < n; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        visited.resize(n+1, false);
        cycleStart = -1;
        dfs(1, -1);
        for (int i = edges.size() - 1; i >= 0; i--) {
            int u = edges[i][0], v = edges[i][1];
            if (cycle.count(u) && cycle.count(v)) {
                return {u, v};
            }
        }
        return {};
    }
    bool dfs(int node, int par){
        if(visited[node]){
            cycleStart = node;
            return true;
        }
        visited[node] = true;
        for(int i : adj[node]){
            if(i == par){
                continue;
            }
            if(dfs(i, node)){
                if(cycleStart != - 1){
                    cycle.insert(node);
                }
                if(node == cycleStart){
                    cycleStart = -1;
                }
                return true;
            }
        }
        return false;
    }
};
