class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for( int i = 0; i < nums.size(); i++){
            set.insert(nums[i]);
        }
        int max = 0;
        for( int x : set){
            if( !set.count(x-1)){
                int len = 1;
                while(set.count(x+1)){
                    len++;
                    x++;
                }
                if( len > max){
                    max = len;
                }
            }
        }
        return max;
    }
};
