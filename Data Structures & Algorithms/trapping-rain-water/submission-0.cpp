class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size());
        vector<int> suffix(height.size());
        int premax = 0; 
        int sufmax = 0;
        for( int i = 0; i < height.size(); i++){
            premax = max(premax, height[i]);
            prefix[i] = premax;
            int j = height.size()-i-1;
            sufmax = max(sufmax, height[j]);
            suffix[j] = sufmax;
        } 
        int res = 0;
        for( int i = 0; i < height.size(); i++){
            res += min(suffix[i], prefix[i]) - height[i];
        }
        return res;
    }
};
