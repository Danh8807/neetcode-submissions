class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        minHeap = []
        res = []
        for i in range(len(points)):
            distance = points[i][0]**2 + points[i][1]**2
            heapq.heappush(minHeap, (-distance, points[i]))
            if len(minHeap) > k:
                heapq.heappop(minHeap)
        while minHeap:
            res.append(heapq.heappop(minHeap)[1])
        return res
        