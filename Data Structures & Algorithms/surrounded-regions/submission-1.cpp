class Solution {
public:
    vector<vector<bool>> visited;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0},
                                         {0, 1}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        visited = vector<vector<bool>>(row, vector<bool>(col, false));
        for(int i = 0; i < row; i++){
            if(board[i][0] == 'O'){
                dfs(board, i, 0);
            }
            if(board[i][col-1] == 'O'){
                dfs(board, i, col -1);
            }
        }
        for(int j = 0; j < col; j++){
            if(board[0][j] == 'O'){
                dfs(board, 0, j);
            }
            if(board[row-1][j] == 'O'){
                dfs(board, row-1, j);
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(visited[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, int i, int j){
        int row = board.size();
        int col = board[0].size();
        visited[i][j] = true;
        for(auto [r,c]: directions){
            int nr = i + r;
            int nc = j + c;
            if(nr >= 0 && nr < row && nc >= 0 && nc < col && !visited[nr][nc] && board[nr][nc] == 'O'){
                dfs(board, nr, nc);
            }
        }
    }
};
