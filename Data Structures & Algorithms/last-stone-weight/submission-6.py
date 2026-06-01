class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = []
        for stone in stones: 
            heapq.heappush(heap, -stone)
        while len(heap) > 1:
            x = heap[0]
            heapq.heappop(heap)
            y = heap[0]
            heapq.heappop(heap)
            if x == y: continue
            else: 
                heapq.heappush(heap, -abs(x - y))
        if len(heap) == 0:
            return 0
        return abs(heap[0])
