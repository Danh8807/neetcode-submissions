class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False;
        arr = {}
        for c in s: 
            arr[c] = arr.get(c, 0) + 1
        for c in t: 
            arr[c] = arr.get(c,0) -1
            if arr[c] < 0:
                return False
        return True
