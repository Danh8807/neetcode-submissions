class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = nums.size()-2;
        int goal = nums.size()-1;
        while(i >= 0){
            if(i + nums[i] >= goal){
                goal = i;
            }
            i--;
        }
        if(goal == 0){
            return true;
        }
        return false;
    }
};
