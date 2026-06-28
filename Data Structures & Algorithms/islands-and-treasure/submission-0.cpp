class Solution {
public:
    set<pair<int,int>> visited;
    queue<pair<int,int>> q; 
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int dist = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                    visited.insert({i,j});
                }
            }
        }
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; i++){
                auto [r,c] = q.front();
                q.pop();
                grid[r][c] = dist;
                addRoom(grid,r+1, c);
                addRoom(grid,r-1, c);
                addRoom(grid,r, c+1);
                addRoom(grid, r, c-1);
            }
            dist++;
        }

    }

    void addRoom(vector<vector<int>>& grid, int i, int j){
        int row = grid.size();
        int col = grid[0].size();
        if(i >= row || i < 0 || j >= col || j < 0|| grid[i][j] == -1 || visited.find({i,j}) != visited.end() ){
            return;
        }
        visited.insert({i, j});
        q.push({i,j});

    }

};
