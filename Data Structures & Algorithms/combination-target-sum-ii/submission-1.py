class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = [] 
        com = []
        def dfs(total, target, i):
            if total == target:
                res.append(com.copy()) 
                return
            if i == len(candidates) or total > target:
                return
            com.append(candidates[i])
            dfs(total + candidates[i], target, i + 1)
            com.pop()
            while i + 1 < len(candidates) and candidates[i+1] == candidates[i]:
                i += 1
            dfs(total, target, i + 1)
        candidates.sort()
        dfs(0, target, 0)
        return res