class Solution {
public:
    vector<int> res;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        dfs(matrix, 0, matrix[0].size()-1, matrix.size()-1,0);
        return res;
    }

    void dfs(vector<vector<int>>& matrix, int a, int b, int c, int d){
        if( a > c || d > b){
            return;
        }
        if(a == c){
            for(int i = d; i <= b; i++) res.push_back(matrix[a][i]);
            return;
        }
        if(d == b){
            for(int i = a; i <= c; i++) res.push_back(matrix[i][d]);
            return;
        }
        for(int i = d; i <= b; i++){
            res.push_back(matrix[a][i]);
        }
        for(int i = a+1; i <= c; i++){
            res.push_back(matrix[i][b]);
        }
        for(int i = b-1; i >= d; i--){
            res.push_back(matrix[c][i]);
        }
        for(int i = c-1; i > a; i--){
            res.push_back(matrix[i][d]);
        }
        dfs(matrix, a+1, b-1, c-1, d+1);

    }
};
