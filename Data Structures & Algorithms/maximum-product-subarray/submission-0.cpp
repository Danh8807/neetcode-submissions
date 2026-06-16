class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMin = 1;
        int curMax = 1;

        for( int num: nums){
            int tmp = curMax*num; 
            curMax = max(num, max(num*curMax, num*curMin));
            curMin = min(num, min(tmp, num*curMin));
            res = max(res, curMax);
        }
        return res;
    }
};
