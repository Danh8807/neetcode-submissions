class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        time = 0
        heap = []
        queue = deque()    
        freq = [0] * 26
        for task in tasks:
            freq[ord(task) - ord('A')] +=1
        for i in freq: 
            if i > 0:
                heapq.heappush(heap,-i);
        while heap or queue:
            time += 1
            if heap:
                tmp = heap[0] + 1
                heapq.heappop(heap)
                if tmp != 0:
                    queue.append((tmp, time + n))
            if queue and queue[0][1] == time:
                tmp = queue[0][0]
                queue.popleft()
                heapq.heappush(heap, tmp)
        return time