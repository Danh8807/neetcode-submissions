class Solution {
public:
    vector<string> board;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        dfs(0, n);
        return res;
    }

    void dfs(int col, int n){
        if(col == n){
            res.push_back(board);
            return;
        }
        for(int i = 0; i < n; i++){
            if(check(i,col, n)){
                board[i][col] = 'Q';
                dfs(col+1, n);
                board[i][col] = '.';
            }
        }
    }

    bool check(int i, int j, int n){
    
    for(int col = 0; col < j; col++){
        if(board[i][col] == 'Q') return false;
    }

    
    for(int r = i-1, c = j-1; r >= 0 && c >= 0; r--, c--){
        if(board[r][c] == 'Q') return false;
    }

    
    for(int r = i+1, c = j-1; r < n && c >= 0; r++, c--){
        if(board[r][c] == 'Q') return false;
    }

    return true;
}
};
