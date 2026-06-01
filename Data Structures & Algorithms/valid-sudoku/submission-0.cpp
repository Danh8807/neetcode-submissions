class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>> squares;
        for( int i = 0; i < 9; i++){
            unordered_set<int> rows;
            unordered_set<int> cols;
            for( int j = 0; j < 9; j++){
                int index = (i/3)*3 + (j/3);
                if(board[i][j] != '.'){
                    if (squares[index].count(board[i][j]) ){
                        return false;
                    }
                    else{
                        squares[index].insert(board[i][j]);
                    }
                }
                if(board[i][j] != '.'){
                    if( rows.count(board[i][j])){
                        return false;
                    }
                    else{
                        rows.insert(board[i][j]);
                    }
                }
                if(board[j][i] != '.'){
                    if( cols.count(board[j][i])){
                        return false;
                    }
                    else{
                        cols.insert(board[j][i]);
                    }
                }
            }
        }
        return true;
    }
};
