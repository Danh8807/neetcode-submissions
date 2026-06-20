class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> res;
    int a = 0, b = matrix[0].size()-1;
    int c = matrix.size()-1, d = 0;
    
    while(a <= c && d <= b){
        
        for(int i = d; i <= b; i++){ 
            res.push_back(matrix[a][i]);
        }
        
        for(int i = a+1; i <= c; i++) {
            res.push_back(matrix[i][b]);
        }
        
        
        if(a < c)
            for(int i = b-1; i >= d; i--){ 
                res.push_back(matrix[c][i]);
            }
        
        if(d < b)
            for(int i = c-1; i > a; i--){ 
                res.push_back(matrix[i][d]);
            }
        a++; 
        b--; 
        c--; 
        d++;
    }
    return res;
    }
};
