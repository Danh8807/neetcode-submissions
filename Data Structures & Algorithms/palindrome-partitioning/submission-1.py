class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def palindrome(j, i):
            while j < i:
                if s[j] != s[i]:
                    return False
                j+=1
                i-=1
            return True
        res = []
        par = [] 
        def dfs(j, i):
            if i >= len(s):
                if(j == i):
                    res.append(par.copy())
                return
            if palindrome(j, i):
                par.append(s[j:i+1])
                dfs(i+1,i+1)
                par.pop()
            dfs(j, i+1)
        dfs(0,0)
        return res
