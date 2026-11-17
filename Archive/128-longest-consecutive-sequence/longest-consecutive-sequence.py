class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        d = {}
        ans = 0

        for i in range(0,len(nums)):
            n = nums[i]
            if n in d:
                continue

            left = d.get(n-1,0)
            right = d.get(n+1,0)
            cur = left+right+1
            
            ans = max(ans,cur)

            d[n] = d[n-left] = d[n+right] = cur
        return ans
        