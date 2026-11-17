class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        d:dict[int,int] = {}
        for i in range(0,len(nums)):
            d[nums[i]] = d.get(nums[i],0) + 1

        h:list[(int,int)] = []
        for ind,val in d.items():
            heapq.heappush(h,(val,ind))
            if len(h) > k:
                heapq.heappop(h)
        
        res: list[int] = []

        for i in range(0,len(h)):
            res.append(h[i][1])
        return res
