class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int,int>> visit;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        }; 

        minHeap.push({grid[0][0], 0, 0});
        visit.insert({0,0});
        while(!minHeap.empty()){
            auto cur = minHeap.top();
            minHeap.pop();
            int t = cur[0];
            int r = cur[1];
            int c = cur[2];
            if( r == n - 1 && c == n - 1){
                return t;
            }
            for(const auto& dir: directions){
                int newr = r + dir[0];
                int newc = c + dir[1];
                if( newr < 0 || newr >= n || newc < 0 || newc >= n || visit.count({newr,newc})){
                    continue;
                }
                visit.insert({newr, newc});
                minHeap.push({max(t, grid[newr][newc]), newr, newc});
            }
        }
        return -1;
    }
};
