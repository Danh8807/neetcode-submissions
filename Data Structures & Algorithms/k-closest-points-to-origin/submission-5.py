class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        res = [] 
        for point in points:
            distance = point[0]**2 + point[1]**2 
            heapq.heappush(heap, (-distance, point)) 
            if len(heap) > k: 
                heapq.heappop(heap) 
        while heap: 
            res.append(heap[0][1])
            heapq.heappop(heap)
        return res
        