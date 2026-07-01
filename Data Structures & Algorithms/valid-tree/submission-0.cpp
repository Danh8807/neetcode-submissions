class Solution {
public:
    unordered_set<int> visit;
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1){
            return false;
        }
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        if(!dfs(0, -1, adj)){
            return false;
        }
        return visit.size() == n;
    }
    bool dfs(int node, int parent, vector<vector<int>> &adj){
        if(visit.count(node)){
            return false;
        }
        visit.insert(node);
        for(int c: adj[node]){
            if(c == parent){
                continue;
            }
            if(!dfs(c, node, adj)){
                return false;
            }
        }
        return true;
    }
};
