class Solution {
public:
    bool status = false;
    bool exist(vector<vector<char>>& board, string word) {
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
    set<pair<int,int>> count;
    void dfs(vector<vector<char>>& board, string word, int row, int col, int i){
        if( i == word.size()){
            status = true;
            return;
        }
        if(count.find({row,col}) != count.end()){
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
        count.insert({row,col});
        dfs(board, word, row-1, col, i + 1);
        dfs(board, word, row +1, col, i + 1);
        dfs(board, word, row, col - 1, i + 1);
        dfs(board, word, row, col + 1, i + 1);
        count.erase({row,col});
    }
    
};
