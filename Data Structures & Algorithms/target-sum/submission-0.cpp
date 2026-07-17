class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, 0, target);
    }

    int dfs(vector<int>& nums, int i, int target){
        if(i == nums.size()){
            return target == 0 ? 1 : 0;
        }
        return dfs(nums, i + 1, target - nums[i]) + dfs(nums, i + 1, target + nums[i]); 
    }

};
