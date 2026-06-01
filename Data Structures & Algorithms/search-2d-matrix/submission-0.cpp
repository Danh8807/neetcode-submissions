class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l1 = 0;
        int r1 = m-1;
        int row = -1;
        while( l1 <= r1){
            int mid_row = (l1+r1)/2;
            if (matrix[mid_row][0] <= target && target <= matrix[mid_row][n - 1]) { 
                row = mid_row; 
                break; 
            }
            if( matrix[mid_row][0] > target){
                r1 = mid_row-1;
            }
            else{
                l1 = mid_row+1;
            }
        }    
        if (row == -1){
            return false;
        }
        int l2 = 0;
        int r2 = n-1;
        while( l2 <= r2){
            int mid = (l2 + r2)/2;
            if( matrix[row][mid] > target){
                r2 = mid - 1;
            }
            else if( matrix[row][mid] < target){
                l2 = mid + 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
