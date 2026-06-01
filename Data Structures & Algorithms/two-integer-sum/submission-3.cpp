class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mmap;
        for(int i = 0; i < nums.size(); i++){
            if( mmap.find(target - nums[i]) != mmap.end()){
                return {mmap[target-nums[i]], i};
            }
            else{
                mmap.insert({nums[i], i});
            }
        }
        return {};
    }
};
