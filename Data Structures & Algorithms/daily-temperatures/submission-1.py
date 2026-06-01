class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        arr = [0]*len(temperatures)
        st = []
        for i in range(len(temperatures)):
            while st and temperatures[i] > st[-1][0]:
                arr[st[-1][1]] = i - st[-1][1]
                st.pop()
            st.append((temperatures[i],i))
        
        return arr