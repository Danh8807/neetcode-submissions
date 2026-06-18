class Solution {
public:
    vector<int> memo;
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n,-1);
        int maxlis = 1;
        for(int i = 0; i < n; i++){
            maxlis = max(maxlis, dfs(nums,i));
        }
        return maxlis;
    }
    int dfs(vector<int>& nums, int i){
        if(memo[i] != -1){
            return memo[i];
        }
        int lis = 1;
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[i] < nums[j]){
                lis = max(lis, 1 + dfs(nums, j));
            }
        }
        return memo[i]= lis;
    }
};
