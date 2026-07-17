class Solution {
public:
    vector<vector<int>> memo;
    int offset;
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if( abs(target) > total){
            return 0; 
        }
        offset = total;
        memo.resize(nums.size() + 1, vector<int>(2 * total + 1, INT_MIN));
        return dfs(nums, 0, target);
    }

    int dfs(vector<int>& nums, int i, int target){
        if (target + offset < 0 || target + offset > 2 * offset) return 0;
        if(i == nums.size()){
            return target == 0 ? 1 : 0;
        }
        if(memo[i][target + offset] != INT_MIN){
            return memo[i][target + offset];
        }
        return memo[i][target + offset] = dfs(nums, i + 1, target - nums[i]) + dfs(nums, i + 1, target + nums[i]); 
    }

};
