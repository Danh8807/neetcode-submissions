class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-s for s in stones]
        heapq.heapify(stones)

        while len(stones) > 1: 
            x = heapq.heappop(stones)
            y = heapq.heappop(stones) 
            if x == y: 
                if len(stones) == 0:
                    return 0
            else:
                heapq.heappush(stones, x - y)
        return abs(stones[0])
