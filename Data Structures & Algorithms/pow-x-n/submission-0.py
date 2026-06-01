class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        elif n < 0:
            return self.myPow(x,n+1)/x
        else:
            return x * self.myPow(x,n-1)