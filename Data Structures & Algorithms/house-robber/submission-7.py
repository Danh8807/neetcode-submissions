class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        rob1 = 0;
        rob2 = 0;
        for i in range(0, len(nums), 1):
            newRob = max(nums[i] + rob1, rob2)
            rob1 = rob2
            rob2 = newRob
        return rob2