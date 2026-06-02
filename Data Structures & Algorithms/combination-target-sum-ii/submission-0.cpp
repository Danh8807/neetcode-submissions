class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, 0);
        return res;
    }
    vector<int> com; 
    void dfs(vector<int>& nums, int sum, int target, int i){
        if(sum == target){
            res.push_back(com);
            return;
        }
        if( i == nums.size() || sum > target){
            return;
        }
        com.push_back(nums[i]);
        dfs(nums, sum + nums[i], target, i+1);
        com.pop_back();
        
        while( i + 1 < nums.size() && nums[i+1] == nums[i]){
            i++;
        }
    
        dfs(nums, sum, target, i+1);
    }
};
