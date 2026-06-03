class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = [] 
        per = []
        count = []
        def dfs():
            if len(per) == len(nums):
                res.append(per.copy())
            for i in range(len(nums)):
                if nums[i] not in count: 
                    count.append(nums[i])
                    per.append(nums[i])
                    dfs()
                    count.pop()
                    per.pop()
        dfs()
        return res