class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        self.res = []
        self.subset = ""
        def dfs(start, close):
            if close > start or start > n:
                return 
            if len(self.subset) == 2*n and start == close:
                self.res.append(self.subset)
                return 
            self.subset += '('
            dfs(start + 1, close)
            self.subset = self.subset[:-1]
            self.subset += ')'
            dfs(start, close + 1)
            self.subset = self.subset[:-1]
        dfs( 0, 0)
        return self.res