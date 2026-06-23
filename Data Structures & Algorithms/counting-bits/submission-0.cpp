class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; i++){
            res.push_back(hammingWeight(i));
        }
        return res;
    }
    int hammingWeight(uint32_t n) {
        int count = 0;
        for(int i = 0; i < 32; i++){
            if( (n >> i) & 1){
                count++;
            }
        }
        return count;
    }
    
};
