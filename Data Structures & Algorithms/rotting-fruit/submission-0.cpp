class Solution {
public:
    // vector<vector<bool> rotten;
    queue<pair<int,int>> q;
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();
        // rotten = vector<vector<bool>>(row, vector<bool>(col, false));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int size = q.size();
            bool rotted = false;
            for(int i = 0; i < size; i++){
                auto [r,c] = q.front();
                q.pop();
                
                if(rot(grid, r+1, c)) rotted = true;
                if(rot(grid, r-1, c)) rotted = true;
                if(rot(grid, r, c+1)) rotted = true;
                if(rot(grid, r, c-1)) rotted = true;
            }
            if(rotted) count++;
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return count;
    }
    bool rot(vector<vector<int>>& grid, int i, int j){
        int row = grid.size();
        int col = grid[0].size();
        if(i >= row || i < 0 || j >= col || j < 0|| grid[i][j] == 2 || grid[i][j] == 0){
            return false;
        }
        grid[i][j] = 2;
        q.push({i,j});
        return true;
    }
};
