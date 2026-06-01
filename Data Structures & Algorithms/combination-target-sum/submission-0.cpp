class Solution {
public:
    vector<vector<int>> res;
    vector<int> com;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums,0, 0, target);
        return res;
    } 
    
    void dfs(vector<int>& nums, int start, int sum, int target){
        if( sum == target){
            res.push_back(com);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            com.push_back(nums[i]);
            sum += nums[i];
            if( sum <= target){
                dfs(nums, i, sum, target);
            }
            sum -= nums[i];
            com.pop_back();
        }
    }
};
