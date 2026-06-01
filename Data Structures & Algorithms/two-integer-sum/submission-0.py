class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        arr = {}
        for i in range( len(nums)):
            x = target - nums[i]
            if x in arr:
                return [arr[x], i]
            else:
                arr[nums[i]] = i
        return [0,0]