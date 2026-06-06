class Solution {
public:
    int ROWS, COLS;
    bool status = false;
    vector<vector<bool>> count;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        count = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));
        for( int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[0].size(); col++){
                dfs(board, word, row, col, 0);
                if(status == true){
                    return true;
                }
            }
        }
        return false;
    }
    void dfs(vector<vector<char>>& board, string word, int row, int col, int i){
        if( i == word.size()){
            status = true;
            return;
        }
        if( 0 > row || row >= board.size()){
            return;
        }
        if(0 > col || col >= board[0].size()){
            return;
        }
        if(board[row][col] != word[i]){
            return;
        }
        if(count[row][col]){
            return;
        }
        count[row][col] = true;
        dfs(board, word, row-1, col, i + 1);
        dfs(board, word, row +1, col, i + 1);
        dfs(board, word, row, col - 1, i + 1);
        dfs(board, word, row, col + 1, i + 1);
        count[row][col] = false;
    }
    
};
