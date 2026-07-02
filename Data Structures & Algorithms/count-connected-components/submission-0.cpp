class Solution {
public:
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int res = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                res++;
            }
        }
        return res;

    }
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited){
        visited[node] = true;
        for(int c: adj[node]){
            if(!visited[c]){
                dfs(c, adj, visited);
            }
        }
    }
};
