class Solution {
public:

    vector<vector<int>> memo;
    vector<vector<int>> directions = {{-1, 0}, {1, 0},
                                      {0, -1}, {0, 1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size(); 
        int res = 0;
        memo.resize(row, vector<int>(col, -1));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                res = max(res, dfs(matrix, i, j, -1));
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j, int preVal){
        int row = matrix.size();
        int col = matrix[0].size();
        if( i >= row || i < 0 || j < 0 || j >= col || matrix[i][j] <= preVal){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        int res = 1;
        for(auto d: directions){
            res = max(res, 1+ dfs(matrix, i + d[0], j + d[1], matrix[i][j]));
        }
        memo[i][j]= res;
        return res;

    }
};
