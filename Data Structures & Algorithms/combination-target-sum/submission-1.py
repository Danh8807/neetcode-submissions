class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        com = []
        def dfs(start, total):
            if total == target:
                res.append(com.copy())
                return 
            for i in range(start, len(nums)):
                com.append(nums[i])
                if( total + nums[i] <= target):
                    dfs(i, total + nums[i])
                com.pop()
        dfs(0, 0)
        return res