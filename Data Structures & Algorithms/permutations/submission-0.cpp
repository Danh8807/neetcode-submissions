class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return res;
    }
    vector<int> per;
    unordered_set<int> count;
    void dfs(vector<int> &nums){
        if(per.size() == nums.size()){
            res.push_back(per);
            return;
        }
        for( int i = 0; i < nums.size(); i++){
            if(count.find(nums[i]) == count.end()){
                count.insert(nums[i]);
                per.push_back(nums[i]);
                dfs(nums);
                per.pop_back();
                count.erase(nums[i]);
            }
        }
    }
};
