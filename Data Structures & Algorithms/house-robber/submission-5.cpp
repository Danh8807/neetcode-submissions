class Solution {
public:
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int rob1 = 0;
        int rob2 = 0;
        for(int i = 0; i < nums.size(); i++){
            int newRob = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = newRob;
        }
        return rob2;
    }
};
