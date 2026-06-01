class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        st = []
        res = 0
        for i in range(len(heights)):
            index = i
            while st and heights[i] <= st[-1][0]:
                area = st[-1][0] * ( i - st[-1][1])
                res = max(res,area)
                index = st[-1][1]
                st.pop() 
            st.append((heights[i], index))
        while st: 
            area2 = st[-1][0] * ( len(heights) - st[-1][1])
            res = max(area2,res)
            st.pop()
        return res