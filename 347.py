class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = Counter(nums)
        heap = []

        for num, freq in counter.items():
            heapq.heappush(heap, (-freq, num))
        
        result = []
        for _ in range(k):
            result.append(heapq.heappop(heap)[1])
        
        return result