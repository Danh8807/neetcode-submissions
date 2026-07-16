class Solution {
public:
    vector<vector<int>> visited;
    int uniquePaths(int m, int n) {
        visited.resize(m, vector<int>(n, -1));
        return dfs(m, n, 0, 0);
    }
    int res = 0;
    int dfs(int m, int n, int i, int j){
        if( i == (m-1) && j == (n-1)){
            return 1;
        }
        if (i >= m || j >= n) return 0;
        if(visited[i][j] != -1){
            return visited[i][j];
        }
        return visited[i][j] = dfs(m, n, i, j + 1) + dfs(m, n, i + 1, j);
    }
};
