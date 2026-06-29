class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0},
                                         {0, 1}, {0, -1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pac(row, vector<bool>(col, false));
        vector<vector<bool>> atl(row, vector<bool>(col, false));
        for(int i = 0; i < row; i++){
            dfs(heights, i, 0, pac);
            dfs(heights, i, col - 1, atl);
        }
        for(int j = 0; j < col; j++){
            dfs(heights, 0, j, pac);
            dfs(heights, row - 1, j, atl);
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(pac[i][j] && atl[i][j]) {
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& ocean){
        int row = heights.size();
        int col = heights[0].size();
        ocean[i][j] = true;
        for(auto [dr,dc]: directions){
            int nr = i + dr;
            int nc = j + dc;
            if(nr >= 0 && nr < row && nc >= 0 && nc < col && !ocean[nr][nc] && heights[nr][nc] >= heights[i][j]){
                dfs(heights, nr, nc, ocean);
            }
        }
    }
};
